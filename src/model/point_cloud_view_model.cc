//
// Created by somatic_robot on 2/26/20.
//

#include <robot_map_editor/model/point_cloud_view_model.hh>
#include <pcl-1.7/pcl/io/ply_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include <robot_map_editor/utils/pcl_to_eigen.hh>

#include <unordered_set>
#include <random>

namespace robot_map_editor {
namespace model {
    PointCloudViewModel::PointCloudViewModel() :
    octree_(0.01),
    pointCloudPtr_(new pcl::PointCloud<pcl::PointXYZ>),
    history_(std::shared_ptr<pcl::PointCloud<pcl::PointXYZ>>(pointCloudPtr_.get())){}

    PointCloudViewModel::~PointCloudViewModel(){
        changed_.disconnect_all_slots();
    }

    boost::signals2::connection PointCloudViewModel::SubscribeChanged(const std::function<void()>& func){
        return changed_.connect(func);
    }

    void PointCloudViewModel::Load(const std::string &path) {
        pcl::PCLPointCloud2 pc2;
        pcl::io::load(path, pc2);
        pcl::fromPCLPointCloud2(pc2, *pointCloudPtr_);
        std::shuffle(pointCloudPtr_->begin(), pointCloudPtr_->end(), std::mt19937(std::random_device()()));
        octree_.setInputCloud(pointCloudPtr_);
        Changed();
    }

    void PointCloudViewModel::Save(const std::string &path) const{
        pcl::PCLPointCloud2 pc2;
        pcl::toPCLPointCloud2(*pointCloudPtr_, pc2);
        pcl::io::save(path, pc2);
    }

    std::vector<somatic::math::Vector3> PointCloudViewModel::PointCloud() const{
        std::vector<somatic::math::Vector3> pc;
        utils::pcl_to_eigen::PclToEigen(*pointCloudPtr_, pc);
        return pc;
    }

    void PointCloudViewModel::SampleSize(const size_t &size) {
        sampleSize_ = size;
    }

    std::vector<somatic::math::Vector3> PointCloudViewModel::PointCloudSample() {
        std::vector<somatic::math::Vector3> pc;
        utils::pcl_to_eigen::PclToEigen(*pointCloudPtr_, pc);
        return std::vector<somatic::math::Vector3>(pc.begin(), pc.begin() + sampleSize_);
    }

    std::vector<int> PointCloudViewModel::Subtract(const Eigen::Vector3d& center, const double& radius) {
        pcl::PointXYZ p;
        utils::pcl_to_eigen::EigenToPcl(center, p);
        std::vector<int> indexesVec;
        std::vector<float> dists;
        octree_.radiusSearch(p, radius, indexesVec, dists);

        auto size = pointCloudPtr_->size();
        std::vector<bool> indexes(size, true);
        for(const auto& ind : indexesVec)
            indexes[ind] = false;
        std::vector<int> indexesToCopy(size - indexesVec.size());
        size_t ind = 0;
        for(size_t i = 0; i < size; i++)
            if(indexes[i]) {
                indexesToCopy[ind] = i;
                ind++;
            }

        pcl::PointCloud<pcl::PointXYZ> newPc(*pointCloudPtr_, indexesToCopy);
        pointCloudPtr_.reset(&newPc);
        Changed();
        return indexesVec;
    }

    void PointCloudViewModel::Move(const Eigen::Affine3d &movement) {
        for(auto& p : *pointCloudPtr_) {
            Eigen::Vector3d eigen;
            utils::pcl_to_eigen::PclToEigen(p, eigen);
            eigen = movement * eigen;
            utils::pcl_to_eigen::EigenToPcl(eigen, p);
        }
        Changed();
    }

    void PointCloudViewModel::Changed() const{
        history_.Changed(*pointCloudPtr_);
        changed_();
    }

}
}