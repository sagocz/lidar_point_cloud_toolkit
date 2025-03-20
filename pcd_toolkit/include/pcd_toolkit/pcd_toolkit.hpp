#ifndef PCD_TOOLKIT__PCD_TOOLKIT_HPP_
#define PCD_TOOLKIT__PCD_TOOLKIT_HPP_

#pragma once

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <opencv2/opencv.hpp>

class PcdToolkit {
public:
    using PointT = pcl::PointXYZ;
    using PointCloudT = pcl::PointCloud<PointT>;

    PcdToolkit() = default;

    static PointCloudT::Ptr pcl_loader(const std::string& filename);

    static void visualize_pcd(PointCloudT::ConstPtr cloud);

    static cv::Mat pcd_to_depthmap(const PointCloudT::Ptr& cloud, int width, int height);
};

#endif