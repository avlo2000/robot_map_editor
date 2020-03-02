//
// Created by Max on 7/25/19.
//

#include <include/robot_map_editor/utils/ogre_visualisation.hh>

namespace  robot_map_editor {
namespace utils {

static uint32_t count = 0;

OgreVisualisation::~OgreVisualisation() {
    Clear();
    for (auto object : debugObjects_)
        Ogre::MaterialManager::getSingleton().remove(object.second.MaterialName);
}

void OgreVisualisation::Clear() {
    for (auto object : debugObjects_)
        sceneManager_->destroySceneNode(object.second.DebugObject);
    debugObjects_.clear();
}

void OgreVisualisation::PoseUpdate(const std::string &visName,const Ogre::Vector3 &position,const Ogre::Quaternion &orientation) {
    auto it = debugObjects_.find(visName);

    if (it == debugObjects_.end())
        return;

    it->second.DebugObject->setPosition(position);
    it->second.DebugObject->setOrientation(orientation);
}


void OgreVisualisation::Visible(const std::string &visName,const bool &visible) {
    auto it = debugObjects_.find(visName);

    if (it == debugObjects_.end())
        return;

    it->second.DebugObject->setVisible(visible);
    it->second.Visible = visible;
}

bool OgreVisualisation::StopVisualisation(const std::string &visName) {
    Visible(visName,false);
    auto debugIt = debugObjects_.find(visName);

    if (debugIt == debugObjects_.end())
        return true;

    debugObjects_.erase(debugIt);
    return true;
}

void OgreVisualisation::AddLine(const std::string &visName, const std::string &materialName,const float &length, std::string style) {
    if (debugObjects_.find(visName) != debugObjects_.end())
        return;

    auto *path = sceneManager_->createManualObject("debugLine" + std::to_string(count));
    auto *node = sceneManager_->getRootSceneNode()->createChildSceneNode();

    if (style == "point") {
        path->begin(materialName, Ogre::RenderOperation::OT_POINT_LIST);
        path->position(Ogre::Vector3::ZERO);
        float l = 0.0;
        while(l < length) {
            path->position(0, 0, l);
            l+= 0.01;
        }
        path->position(0, 0, length);
        path->end();
    } else {
        path->begin(materialName, Ogre::RenderOperation::OT_LINE_LIST);
        path->position(Ogre::Vector3::ZERO);
        path->position(0, 0, length);
        path->end();
    }

    count++;
    node->attachObject(path);

    utils::OgreConfig ogreDebugConfig("debugLine"+std::to_string(count),materialName, node, false);
    debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

void OgreVisualisation::AddPointCloud(const std::string &visName, const std::string &materialName,
                                               std::vector<Ogre::Vector3> &positions) {
    if (debugObjects_.find(visName) != debugObjects_.end())
        return;

    auto *pc = sceneManager_->createManualObject("debugPC" + std::to_string(count));
    auto *node = sceneManager_->getRootSceneNode()->createChildSceneNode();

    pc->begin(materialName, Ogre::RenderOperation::OT_POINT_LIST);
    for (auto &point : positions)
        pc->position(point);
    pc->end();
    count++;
    node->attachObject(pc);

    utils::OgreConfig ogreDebugConfig("debugPC"+std::to_string(count),materialName, node, false);
    debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

void OgreVisualisation::AddArrow(const std::string &visName, const std::string &materialName,const float &length) {
    if (debugObjects_.find(visName) != debugObjects_.end())
        return;

    auto *path = sceneManager_->createManualObject("debugArrow" + std::to_string(count));
    auto *node = sceneManager_->getRootSceneNode()->createChildSceneNode();

    path->begin(materialName, Ogre::RenderOperation::OT_LINE_LIST);
    path->position(Ogre::Vector3::ZERO);
    path->position(0, 0, length);

    path->position(0, 0, length);
    path->position(0.1, 0, length - 0.1);

    path->position(0, 0, length);
    path->position(-0.1, 0, length - 0.1);

    path->position(0, 0, length);
    path->position(0, 0.1, length - 0.1);

    path->position(0, 0, length);
    path->position(0, -0.1, length - 0.1);
    path->end();

    count++;
    node->attachObject(path);

    utils::OgreConfig ogreDebugConfig("debugArrow" + std::to_string(count),materialName, node, false);
    debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

void OgreVisualisation::AddSphere(const std::string &visName, const std::string &materialName, const float &scale) {
    if (debugObjects_.find(visName) != debugObjects_.end())
        return;

    auto *entity = sceneManager_->createEntity("debugSphere" + std::to_string(count),
                                               Ogre::SceneManager::PT_SPHERE);
    entity->setMaterialName(materialName);

    auto *sphere = sceneManager_->getRootSceneNode()->createChildSceneNode(
            "debugSphereNode" + std::to_string(count));
    sphere->attachObject(entity);
    sphere->setScale(scale,scale,scale);
    sphere->setVisible(true);

    count++;

    utils::OgreConfig ogreDebugConfig("debugSphere" + std::to_string(count),materialName, sphere, false);
    debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

void OgreVisualisation::AddCircle(const std::string &visName, const std::string &materialName,
                                       const double &radius, const double &thickness, const double &accuracy) {
    if (debugObjects_.find(visName) != debugObjects_.end())
        return;

    Ogre::ManualObject *moveArea = sceneManager_->createManualObject("debugCircle" + std::to_string(count));
    moveArea->begin(materialName, Ogre::RenderOperation::OT_TRIANGLE_LIST);

    unsigned index = 0;
    for (float theta = 0; theta <= 2 * M_PI; theta += M_PI / accuracy) {
        moveArea->position(radius * cos(theta), radius * sin(theta), 0);
        moveArea->position(radius * cos(theta - M_PI / accuracy), radius * sin(theta - M_PI / accuracy), 0);
        moveArea->position((radius - thickness) * cos(theta - M_PI / accuracy),
                           (radius - thickness) * sin(theta - M_PI / accuracy), 0);
        moveArea->position((radius - thickness) * cos(theta), (radius - thickness) * sin(theta), 0);
        moveArea->quad(index, index + 1, index + 2, index + 3);
        index += 4;
    }
    moveArea->end();

    auto *circle = sceneManager_->getRootSceneNode()->createChildSceneNode();
    circle->attachObject(moveArea);

    count++;

    utils::OgreConfig ogreDebugConfig("debugCircle" + std::to_string(count),materialName, circle, false);
    debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

void OgreVisualisation::AddPlane(const std::string &visName, const std::string &materialName,
                                      const float &height, const float &width) {
    if (debugObjects_.find(visName) != debugObjects_.end())
        return;

    auto movableInfoPanel = new Ogre::MovablePlane("debugPanel" + std::to_string(count));
    movableInfoPanel->d = 0;
    movableInfoPanel->normal = Ogre::Vector3::UNIT_Z;


    Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().createPlane("debugPanel" + std::to_string(count),
                                                                       "rviz", *movableInfoPanel, width, height,
                                                                       1, 1, true, 1, 1, 1,
                                                                       Ogre::Vector3::UNIT_Y);

    auto *entity = sceneManager_->createEntity("debugPanel" + std::to_string(count));
    entity->setMaterialName(materialName);

    auto *panel = sceneManager_->getRootSceneNode()->createChildSceneNode();
    count++;
    panel->attachObject(entity);

    utils::OgreConfig ogreDebugConfig("debugPanel" + std::to_string(count),materialName, panel, false);
    debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

void OgreVisualisation::AddBox(const std::string &visName, const std::string &materialName,
                                        const std::string &meshName) {
        if (debugObjects_.find(visName) != debugObjects_.end())
            return;

        auto *entity = sceneManager_->getEntity(meshName);
        auto *box = sceneManager_->createManualObject("debugBox" + std::to_string(count));
        auto *node = sceneManager_->getRootSceneNode()->createChildSceneNode();

        box->begin(materialName, Ogre::RenderOperation::OT_LINE_LIST);

        auto width = (entity->getWorldBoundingBox().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM) -
                      entity->getWorldBoundingBox().getCorner(
                              Ogre::AxisAlignedBox::CornerEnum::FAR_RIGHT_BOTTOM)).length();

        auto longitude = (
                entity->getWorldBoundingBox().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM) -
                entity->getWorldBoundingBox().getCorner(
                        Ogre::AxisAlignedBox::CornerEnum::NEAR_LEFT_BOTTOM)).length();

        auto height = (entity->getWorldBoundingBox().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM) -
                       entity->getWorldBoundingBox().getCorner(
                               Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_TOP)).length();

        box->position(Ogre::Vector3::ZERO);
        box->position(width, 0, 0);

        box->position(width, 0, 0);
        box->position(width, longitude, 0);

        box->position(width, longitude, 0);
        box->position(0, longitude, 0);

        box->position(0, longitude, 0);
        box->position(0, 0, 0);

        box->position(0, 0, 0);
        box->position(0, 0, height);

        box->position(width, 0, 0);
        box->position(width, 0, height);

        box->position(width, longitude, 0);
        box->position(width, longitude, height);

        box->position(0, longitude, 0);
        box->position(0, longitude, height);

        box->position(0, 0, height);
        box->position(width, 0, height);

        box->position(width, 0, height);
        box->position(width, longitude, height);

        box->position(width, longitude, height);
        box->position(0, longitude, height);

        box->position(0, longitude, height);
        box->position(0, 0, height);

        box->end();

        count++;
        node->attachObject(box);

        utils::OgreConfig ogreDebugConfig("debugBox" + std::to_string(count),materialName, node, false);
        debugObjects_.insert(std::make_pair(visName, ogreDebugConfig));
}

}}
