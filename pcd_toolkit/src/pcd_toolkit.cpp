#include "pcd_toolkit/pcd_toolkit.hpp"

#include <iostream>
#include <thread>
#include <chrono>

#include "pcd_toolkit/utils.hpp"

PcdToolkit::PointCloudT::Ptr PcdToolkit::pcl_loader(const std::string& filename) {
    PointCloudT::Ptr cloud(new PointCloudT);
    if (pcl::io::loadPCDFile<PointT>(filename, *cloud) == -1) {
        PCL_ERROR("Nie można załadować pliku PCD: %s\n", filename.c_str());
        return nullptr;
    }
    return cloud;
}

void PcdToolkit::visualize_pcd(PointCloudT::ConstPtr cloud) {
    using namespace std::chrono_literals;

    pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer ("3D Viewer"));

    viewer->setBackgroundColor (0, 0, 0);
    viewer->addPointCloud<PointT> (cloud, "sample cloud");
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
    viewer->addCoordinateSystem (1.0);

    while (!viewer->wasStopped ())
    {
        viewer->spinOnce (100);
        std::this_thread::sleep_for(100ms);
    }
}

cv::Mat PcdToolkit::pcd_to_depthmap(const PointCloudT::Ptr& cloud, int width, int height) {
    auto mat_k = get_k_matrix(120.0, static_cast<float>(width), static_cast<float>(height));
    Eigen::Matrix4f T_LC;
    T_LC <<  0,  1,  0, 0,
             0,  0, -1, 0,
             1,  0,  0, 0,
             0,  0,  0, 1;
    std::cout << mat_k << std::endl;
    cv::Mat depthmap(height, width, CV_32F, cv::Scalar(0));
    for (const auto& point : cloud->points) {
        Eigen::Vector4f P_L(point.x, point.y, point.z, 1.0);
        Eigen::Vector4f P_C = T_LC * P_L;  // Transform LiDAR → Camera
        
        if (P_C.z() <= 0) continue;

        Eigen::Vector3f P_N = mat_k * P_C.head<3>();
        int u = static_cast<int>(P_N.x() / P_N.z());
        int v = static_cast<int>(P_N.y() / P_N.z());

        if (u >= 0 && u < width && v >= 0 && v < height) {
            float& depth = depthmap.at<float>(v, u);
            if (depth == 0 || P_C.z() < depth) {
                depth = P_C.z();
            }
        }
    }
    return depthmap;
}