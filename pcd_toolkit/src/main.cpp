#include <boost/program_options.hpp>

#include "pcd_toolkit/pcd_manager.hpp"

int main(int argc, char** argv) {
    namespace po = boost::program_options;
    std::string pcd_file;
    bool visualize = false, convert_depthmap = false;

    po::options_description desc("Options");
    desc.add_options()
        ("help,h", "Show help")
        ("pcd-file-path", po::value<std::string>(&pcd_file), "PCD file path")
        ("visualize-pcd", po::bool_switch(&visualize), "Show point cloud")
        ("pcd-to-depth", po::bool_switch(&convert_depthmap), "Convert pcd file to depth map");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help") || pcd_file.empty()) {
        std::cout << desc << "\n";
        return 1;
    }

    PcdManager manager;
    manager.process(pcd_file, visualize, convert_depthmap);
    return 0;
}