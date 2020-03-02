//
// Created by somatic_robot on 2/27/20.
//

#ifndef ROBOT_MAP_EDITOR_MAP_POINT_CLOUD_HH
#define ROBOT_MAP_EDITOR_MAP_POINT_CLOUD_HH
#include <rviz_visual_tools/rviz_visual_tools.h>
#include <include/robot_map_editor/utils/ogre_visualisation.hh>
#include <somatic_math/Vector.hh>

namespace robot_map_editor {
namespace ogre_helpers {

    class MapPointCloud {
    public:
        MapPointCloud(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode);
    public:
        void VisualiseAll(const std::vector<somatic::math::Vector3> &pc);

        void Remove(const std::vector<int> &indexes);

        void Clear();
    private:
        rviz_visual_tools::colors color = rviz_visual_tools::colors::BLUE;
        rviz_visual_tools::scales scales = rviz_visual_tools::scales::MEDIUM;
        std::string name = "map_point_cloud";

        rviz_visual_tools::RvizVisualTools visualTools_;
        utils::OgreDebugVisualisationPtr ogreDebugVisualisationPtr_;
        Ogre::MaterialPtr material_;
    };

}}
#endif //ROBOT_MAP_EDITOR_MAP_POINT_CLOUD_HH
