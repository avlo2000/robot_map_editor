//
// Created by Max on 7/25/19.
//

#ifndef ROBOT_MAP_EDITOR_OGRE_VISUALISATION_HH
#define ROBOT_MAP_EDITOR_OGRE_VISUALISATION_HH

#include <Ogre.h>
#include <OgreSceneManager.h>
#include <ros/ros.h>
#include <OgreWireBoundingBox.h>

namespace  robot_map_editor {
namespace utils {

struct OgreConfig {
public:
    OgreConfig(std::string objName,std::string materialName,Ogre::SceneNode* debugObjects, bool visible)
    : ObjectName(objName),
    MaterialName(materialName),
    DebugObject(debugObjects),
    Visible(visible) {}

public:
    std::string ObjectName;
    std::string MaterialName;
    Ogre::SceneNode* DebugObject;
    bool Visible;
};

class OgreVisualisation {
public:
    explicit OgreVisualisation(Ogre::SceneManager *sceneManager) : sceneManager_(sceneManager) {}

    ~OgreVisualisation();

    void Clear();

    void AddLine(const std::string &visName, const std::string &materialName, const float &length, std::string style = "line");

    void AddPointCloud(const std::string &visName, const std::string &materialName,
                                               std::vector<Ogre::Vector3> &positions);

    void AddArrow(const std::string &visName, const std::string &materialName, const float &length);

    void AddSphere(const std::string &visName, const std::string &materialName, const float &scale);

    void AddCircle(const std::string &visName,const std::string &materialName,const double &radius,const double &thickness,const double &accuracy);

    void AddPlane(const std::string &visName,const std::string &materialName,const float &height,const float &width);

    void AddBox(const std::string &visName, const std::string &materialName,const std::string &meshName);

    void PoseUpdate(const std::string &visName,const Ogre::Vector3 &position,const Ogre::Quaternion &orientation);

    void Visible(const std::string &visName,const bool &visible);

    bool StopVisualisation(const std::string &visName);

private:
    Ogre::SceneManager *sceneManager_;
    std::map<std::string, utils::OgreConfig> debugObjects_;
};

using OgreDebugVisualisationPtr = std::shared_ptr<OgreVisualisation>;




}
}




#endif //ROBOT_MAP_EDITOR_OGRE_VISUALISATION_HH
