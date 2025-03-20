#define _USE_MATH_DEFINES

#include <Eigen/Dense>
#include <math.h>

Eigen::Matrix3f get_k_matrix(const float& fov, const float& img_w, const float& img_h) {
    float focal;
    focal = img_w / (2 * tan(fov * M_PI / 360.0));

    Eigen::Matrix3f k_matrix = Eigen::Matrix3f::Identity(3, 3);
    k_matrix(0,0) = focal;
    k_matrix(1,1) = focal;

    k_matrix(0,2) = img_w / 2.0;
    k_matrix(1,2) = img_h / 2.0;

    return k_matrix;
}