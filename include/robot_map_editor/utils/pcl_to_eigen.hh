//
// Created by somatic_robot on 2/28/20.
//

#ifndef ROBOT_MAP_EDITOR_PCL_TO_EIGEN_HH
#define ROBOT_MAP_EDITOR_PCL_TO_EIGEN_HH


#include <pcl-1.7/pcl/point_types.h>
#include <pcl-1.7/pcl/point_cloud.h>

namespace  robot_map_editor {
namespace utils {
namespace pcl_to_eigen {
    void PclToEigen(const pcl::PointXYZ& pcl, Eigen::Vector3d& eigen);

    void PclToEigen(const pcl::PointCloud<pcl::PointXYZ>& pcl, std::vector<Eigen::Vector3d>& eigen);

    void EigenToPcl(const Eigen::Vector3d& eigen, pcl::PointXYZ& pcl);
}
}
}

#endif //ROBOT_MAP_EDITOR_PCL_TO_EIGEN_HH
