#ifndef PCD_TOOLKIT__PCD_MANAGER_HPP_
#define PCD_TOOLKIT__PCD_MANAGER_HPP_

#include "pcd_toolkit.hpp"

class PcdManager {
public:
    PcdManager() = default;
    void process(const std::string& pcd_file, bool visualize, bool convert_depthmap);
};

#endif