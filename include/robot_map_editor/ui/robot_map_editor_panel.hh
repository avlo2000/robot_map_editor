//
// Created by Denys Kotelovych on 1/14/19.
//

#ifndef ROBOT_MAP_EDITOR_ROBOT_MAP_EDITOR_PANEL_HH
#define ROBOT_MAP_EDITOR_ROBOT_MAP_EDITOR_PANEL_HH

#include <rviz/panel.h>
#include <robot_map_editor/model/point_cloud_view_model.hh>
#include <robot_map_editor/controllers/ogre_controller.hh>

#ifndef Q_MOC_RUN

#endif

namespace Ui {
class RobotMapEditorPanelUI;
}

namespace robot_map_editor {
namespace ui {

class RobotMapEditorPanel final : public rviz::Panel {
Q_OBJECT
public:
    explicit RobotMapEditorPanel(QWidget *parent = nullptr);

    ~RobotMapEditorPanel() override;

    void onInitialize() override;

private Q_SLOTS:
    void LoadPcButtonClicked();

    void SavePlanButtonClicked();

    void OnUpdate();
private:
    void InitControllers();

    void InitResources();

    void InitResourcesInternal(std::string path);

    void InitControls();
private:
    Ui::RobotMapEditorPanelUI *ui_;
    QTimer *updateTimer_;

    model::PointCloudViewModelPtr viewModelPtr_;
    controllers::OgreControllerPtr ogreControllerPtr_;
};

} // end namespace somatic
}

#endif //ROBOT_MAP_EDITOR_ROBOT_MAP_EDITOR_PANEL_HH
