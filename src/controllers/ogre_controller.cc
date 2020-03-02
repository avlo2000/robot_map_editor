//
// Created by somatic_robot on 2/27/20.
//

#include "include/robot_map_editor/controllers/ogre_controller.hh"

namespace robot_map_editor{
namespace controllers {
    OgreController::OgreController(rviz::VisualizationManager *visManager,
                                     robot_map_editor::model::PointCloudViewModel &viewModel) : viewModel_(viewModel),
                                                                                                    visManager_(visManager),
                                                                                                    ogre_(visManager_.get()){
        pointCloudChanged_ = viewModel_.SubscribeChanged(std::bind(&OgreController::DrawPointCloudSample, this));
    }

    void OgreController::DrawPointCloudSample(){
        viewModel_.SampleSize(10000);
        ogre_.PointCloud.VisualiseAll(viewModel_.PointCloudSample());
    }

    Ogre::SceneManager* OgreController::SceneManager(){
        return ogre_.SceneManager;
    }

    OgreController::~OgreController() {
        pointCloudChanged_.disconnect();
    }
}}