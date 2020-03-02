//
// Created by somatic_robot on 2/28/20.
//

#include <robot_map_editor/utils/pcl_to_eigen.hh>

namespace  robot_map_editor {
namespace utils {
namespace pcl_to_eigen {
    void PclToEigen(const pcl::PointXYZ& pcl, Eigen::Vector3d& eigen){
        eigen.x() = pcl.x;
        eigen.y() = pcl.y;
        eigen.z() = pcl.z;
    }

    void PclToEigen(const pcl::PointCloud<pcl::PointXYZ>& pcl, std::vector<Eigen::Vector3d>& eigen){
        eigen.clear();
        for(const auto& p : pcl)
            eigen.emplace_back(Eigen::Vector3d(p.x, p.y, p.z));
    }

    void EigenToPcl(const Eigen::Vector3d& eigen, pcl::PointXYZ& pcl){
        pcl.x = eigen.x();
        pcl.y = eigen.y();
        pcl.z = eigen.z();
    }
}
}
}