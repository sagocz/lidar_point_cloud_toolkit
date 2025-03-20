#include "pcd_toolkit/pcd_manager.hpp"


void PcdManager::process(const std::string& pcd_file, bool visualize, bool convert_depthmap) {
        PcdToolkit toolkit;
        auto cloud = toolkit.pcl_loader(pcd_file);
        if (!cloud) {
            return;
        }
        if (visualize) {
            toolkit.visualize_pcd(cloud);
        }
        if (convert_depthmap) {
            cv::Mat depthmap = toolkit.pcd_to_depthmap(cloud, 640, 480);

            cv::Mat depthmap_norm;
            double minVal, maxVal;
            cv::minMaxLoc(depthmap, &minVal, &maxVal);
            depthmap.convertTo(depthmap_norm, CV_8U, 255 / (maxVal - minVal), -minVal * 255 / (maxVal - minVal));

            cv::Mat depthmap_color;
            cv::applyColorMap(depthmap_norm, depthmap_color, cv::COLORMAP_JET);

            cv::imwrite("depthmap.png", depthmap_color);
            std::cout << "Depth map saved as depthmap.png\n";
        }
    }