//
// Created by somatic_robot on 2/27/20.
//

#ifndef ROBOT_MAP_EDITOR_OGRE_VISUALS_HH
#define ROBOT_MAP_EDITOR_OGRE_VISUALS_HH
#include <rviz/visualization_manager.h>
#include <rviz_vr/ogre_helpers/pointer.hh>
#include <robot_map_editor/ogre_helpers/map_point_cloud.hh>

namespace robot_map_editor {
namespace ogre_helpers {
    struct OgreVisuals {
        OgreVisuals(rviz::VisualizationManager *visManager)
                : SceneManager(visManager->getSceneManager()),
                  ParentNode(SceneManager->getRootSceneNode()),
                  PointCloud(SceneManager, ParentNode){}

        Ogre::SceneManager *SceneManager;
        Ogre::SceneNode *ParentNode;

        MapPointCloud PointCloud;
    };
}}

#endif //ROBOT_MAP_EDITOR_OGRE_VISUALS_HH
