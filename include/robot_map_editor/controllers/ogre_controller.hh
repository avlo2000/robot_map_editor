//
// Created by somatic_robot on 2/27/20.
//

#ifndef ROBOT_MAP_EDITOR_OGRE_CONTROLLER_HH
#define ROBOT_MAP_EDITOR_OGRE_CONTROLLER_HH
#include <rviz_vr/ogre_helpers/pointer.hh>
#include <rviz_vr/utils/ray.h>
#include <rviz/visualization_manager.h>

#include <robot_map_editor/model/point_cloud_view_model.hh>
#include <robot_map_editor/ogre_helpers/ogre_visuals.hh>

namespace robot_map_editor {
namespace controllers {

    class OgreController {
    public:
        OgreController(rviz::VisualizationManager *visManager, model::PointCloudViewModel& viewModel);

        virtual ~OgreController();

        Ogre::SceneManager* SceneManager();
    private:
        void DrawPointCloudSample();
    private:
        boost::signals2::connection pointCloudChanged_;
    private:
        std::shared_ptr<rviz::VisualizationManager> visManager_;
        model::PointCloudViewModel& viewModel_;
        ogre_helpers::OgreVisuals ogre_;
    };

    using OgreControllerPtr = std::shared_ptr<OgreController>;

}}
#endif //ROBOT_MAP_EDITOR_OGRE_CONTROLLER_HH
