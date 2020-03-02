//
// Created by somatic_robot on 2/27/20.
//

#include <robot_map_editor/ogre_helpers/map_point_cloud.hh>

namespace robot_map_editor {
namespace ogre_helpers {
    MapPointCloud::MapPointCloud(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode) : visualTools_("/world", "/map_editor_point_cloud"){
        ogreDebugVisualisationPtr_ = std::make_shared<utils::OgreVisualisation>(sceneManager);

        material_ = Ogre::MaterialManager::getSingleton().create("PointCloudMaterial", "map_editor");
        material_->setLightingEnabled(false);
        material_->getTechnique(0)->getPass(0)->setSceneBlending(Ogre::SceneBlendType::SBT_TRANSPARENT_ALPHA);
        material_->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
        material_->getTechnique(0)->getPass(0)->setPointSize(1);
        material_->getTechnique(0)->getPass(0)->createTextureUnitState();
        material_->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setColourOperationEx(
                Ogre::LBX_SOURCE1,Ogre::LBS_MANUAL,Ogre::LBS_CURRENT,Ogre::ColourValue(0,1,0,1));
    }

    void MapPointCloud::VisualiseAll(const std::vector<somatic::math::Vector3> &pc) {
        if (pc.empty())
            return;

        ogreDebugVisualisationPtr_->Clear();

        std::vector<Ogre::Vector3> points;
        for(const auto& p : pc)
            points.emplace_back(p.x(), p.y(), p.z());
        ogreDebugVisualisationPtr_->AddPointCloud("map_editor_point_cloud", material_->getName(), points);
        ogreDebugVisualisationPtr_->Visible("map_editor_point_cloud", true);
        visualTools_.trigger();
    }

    void MapPointCloud::Remove(const std::vector<int> &indexes) {
        ogreDebugVisualisationPtr_->
    }
}}