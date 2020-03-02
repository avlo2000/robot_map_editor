//
// Created by Denys Kotelovych on 12/31/18.
//

#ifndef ROBOT_TRAJECTORY_EDITOR_TRIANGLE_LIST_HH
#define ROBOT_TRAJECTORY_EDITOR_TRIANGLE_LIST_HH

#include <OgreMaterial.h>

namespace Ogre {
class SceneManager;

class SceneNode;

class ManualObject;
}

namespace robot_map_editor {
namespace ogre_helpers {

class ObjectList {
public:
    ObjectList(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode, std::string materialName = "");

    virtual ~ObjectList();
public:
    virtual void Points(const std::vector<Ogre::Vector3> &points) = 0;

    void Position(const Ogre::Vector3 &position);

    void Orientation(const Ogre::Quaternion &orientation);

    void Color(const Ogre::ColourValue &color);

    void Visible(bool visible);

    Ogre::Quaternion& Orientation();
protected:
    Ogre::SceneManager *sceneManager_;
    Ogre::SceneNode *sceneNode_;
    Ogre::ManualObject *manualObject_;
    Ogre::MaterialPtr material_;
    std::string materialName_;
    std::vector<Ogre::Vector3> points_;
};

class TriangleList : public ObjectList {
public:
    TriangleList(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode, std::string materialName = "")  : ObjectList(sceneManager, parentNode, materialName) {}

    ~TriangleList() override = default;
public:
    void Points(const std::vector<Ogre::Vector3> &points) override;
};

class MenuTriangleList : public TriangleList {
public:
    MenuTriangleList(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode, std::string materialName)
        : TriangleList(sceneManager, parentNode, std::move(materialName)) {}

    ~MenuTriangleList() override = default;
public:


    void Points(const std::vector<Ogre::Vector3> &corners, const std::vector<Ogre::Vector2> &points);

    int RowIndex() const;

    int ColIndex() const;

    void Index(int row, int col);

private:
    int rowIndex{}, colIndex{};
};

class LineList : public  ObjectList {
public:
    LineList(Ogre::SceneManager *sceneManager, Ogre::SceneNode *parentNode) : ObjectList(sceneManager, parentNode) {}

    ~LineList() override = default;
public:
    void Points(const std::vector<Ogre::Vector3> &points) override;
};

}
}

#endif //ROBOT_TRAJECTORY_EDITOR_TRIANGLE_LIST_HH
