//
// Created by somatic_robot on 2/26/20.
//

#ifndef ROBOT_MAP_EDITOR_POINT_CLOUD_VIEW_MODEL_HH
#define ROBOT_MAP_EDITOR_POINT_CLOUD_VIEW_MODEL_HH

#include <pcl-1.7/pcl/point_cloud.h>
#include <pcl-1.7/pcl/point_types.h>
#include <pcl-1.7/pcl/PCLPointCloud2.h>
#include <somatic_math/Vector.hh>
#include <pcl-1.7/pcl/search/octree.h>
#include <robot_map_editor/utils/history.hh>
#include <boost/signals2.hpp>

namespace robot_map_editor {
namespace model {
    class PointCloudViewModel {
    public:
        PointCloudViewModel();

        ~PointCloudViewModel();
    public:
        boost::signals2::connection SubscribeChanged(const std::function<void()>& func);
    public:
        void Load(const std::string& path);

        void Save(const std::string& path) const;

        std::vector<somatic::math::Vector3> PointCloud() const;

        std::vector<somatic::math::Vector3> PointCloudSample();

        void Move(const Eigen::Affine3d& movement);

        std::vector<int> Subtract(const Eigen::Vector3d& center, const double& radius);

        void SampleSize(const size_t &size);
    private:
        void Changed() const;
    private:
        size_t sampleSize_;
        pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloudPtr_;
        pcl::search::Octree<pcl::PointXYZ> octree_;
    private:
        mutable utils::History<pcl::PointCloud<pcl::PointXYZ>> history_;
    private:
        boost::signals2::signal<void()> changed_;
    };

    typedef std::shared_ptr<PointCloudViewModel> RobotMapEditorViewModelPtr;
}
}
#endif //ROBOT_MAP_EDITOR_POINT_CLOUD_VIEW_MODEL_HH
