//
// Created by Denys Kotelovych on 12/31/18.
//

#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreManualObject.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreTechnique.h>
#include <robot_map_editor/ogre_helpers/object_list.hh>

namespace robot_map_editor {
namespace ogre_helpers {

ObjectList::ObjectList(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode, std::string materialName)
        : sceneManager_(sceneManager), sceneNode_(parentNode->createChildSceneNode()) {
    static uint32_t count = 0;
    materialName_ = materialName;
    manualObject_ = sceneManager_->createManualObject(materialName_ + std::to_string(count));
    count++;
    sceneNode_->attachObject(manualObject_);

    if (Ogre::MaterialManager::getSingleton().resourceExists(materialName_) ) {
        material_ = static_cast<Ogre::MaterialPtr>(Ogre::MaterialManager::getSingleton().getByName(materialName_));
        material_->setCullingMode(Ogre::CULL_NONE);
        material_->load();
    } else {
        material_ = Ogre::MaterialManager::getSingleton().create( materialName_, "rviz");
        material_->getTechnique(0)->getPass(0)->createTextureUnitState( materialName_ );
        material_->setReceiveShadows(false);
        material_->getTechnique(0)->setLightingEnabled(false);
        material_->setCullingMode(Ogre::CULL_NONE);

    }
}

ObjectList::~ObjectList() {
    sceneManager_->destroySceneNode(sceneNode_);
    sceneManager_->destroyManualObject(manualObject_);
    material_->unload();
    Ogre::MaterialManager::getSingleton().remove(materialName_);
}

void TriangleList::Points(const std::vector<Ogre::Vector3> &points) {
    assert(points.size() % 3 == 0);

    if (points_.size() == points.size()) {
        manualObject_->beginUpdate(0);
    } else {
        manualObject_->clear();
        manualObject_->estimateVertexCount(points.size());
        manualObject_->begin(materialName_, Ogre::RenderOperation::OT_TRIANGLE_LIST);
    }


    for (size_t i = 0; i < points.size(); i += 3) {
        std::vector<Ogre::Vector3> corners(3);
        for (size_t c = 0; c < 3; c++)
            corners[c] = points[i + c];

        Ogre::Vector3 normal = (corners[1] - corners[0]).crossProduct(corners[2] - corners[0]);
        normal.normalise();

        for (size_t c = 0; c < 3; c++) {
            manualObject_->position(corners[c]);
            manualObject_->normal(normal);
        }
    }

    manualObject_->end();
}

void ObjectList::Position(const Ogre::Vector3 &position) {
    sceneNode_->setPosition(position);
}

void ObjectList::Orientation(const Ogre::Quaternion &orientation) {
    sceneNode_->setOrientation(orientation);
}

void ObjectList::Color(const Ogre::ColourValue &color) {
    material_->getTechnique(0)->setLightingEnabled(false);
    material_->getTechnique(0)->setAmbient(color);
    material_->getTechnique(0)->setDiffuse(color);
    material_->getTechnique(0)->setSelfIllumination(color); // FIXME: using this to avoid lighting

    if (color.a < 0.998f) {
        material_->getTechnique(0)->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
        material_->getTechnique(0)->setDepthWriteEnabled(false);
    } else {
        material_->getTechnique(0)->setSceneBlending(Ogre::SBT_REPLACE);
        material_->getTechnique(0)->setDepthWriteEnabled(true);
    }
}

void ObjectList::Visible(bool visible) {
    sceneNode_->setVisible(visible, true);
}

Ogre::Quaternion& ObjectList::Orientation() {
    return const_cast<Ogre::Quaternion &>(sceneNode_->getOrientation());
}

void MenuTriangleList::Points(const std::vector<Ogre::Vector3> &corners, const std::vector<Ogre::Vector2> &points) {
    manualObject_->clear();
    manualObject_->estimateVertexCount(4);
    manualObject_->begin(materialName_, Ogre::RenderOperation::OT_TRIANGLE_LIST);

    Ogre::Vector3 normal = (corners[1] - corners[0]).crossProduct(corners[2] - corners[1]);
    normal.normalise();

    manualObject_->position(corners[0]);
    manualObject_->normal(normal);
    manualObject_->textureCoord(points[0]);

    manualObject_->position(corners[1]);
    manualObject_->normal(normal);
    manualObject_->textureCoord(points[1]);

    manualObject_->position(corners[2]);
    manualObject_->normal(normal);
    manualObject_->textureCoord(points[2]);

    manualObject_->position(corners[1]);
    manualObject_->normal(normal);
    manualObject_->textureCoord(points[1]);

    manualObject_->position(corners[3]);
    manualObject_->normal(normal);
    manualObject_->textureCoord(points[3]);

    manualObject_->position(corners[2]);
    manualObject_->normal(normal);
    manualObject_->textureCoord(points[2]);

    manualObject_->end();
}

int MenuTriangleList::RowIndex() const {
    return rowIndex;
}

int MenuTriangleList::ColIndex() const {
    return colIndex;
}

void MenuTriangleList::Index(int row, int col) {
    rowIndex = row;
    colIndex = col;
}

void LineList::Points(const std::vector<Ogre::Vector3> &points) {
    if (points_.size() == points.size()) {
        manualObject_->beginUpdate(0);
    } else {
        manualObject_->clear();
        manualObject_->estimateVertexCount(points.size());
        manualObject_->begin(materialName_, Ogre::RenderOperation::OT_LINE_LIST);
    }

    for (size_t i = 0; i < points.size(); i++) {
        manualObject_->position(points[i]);
    }

    manualObject_->end();
}

}
}