//
// Created by somatic_robot on 3/2/20.
//

#ifndef ROBOT_MAP_EDITOR_IO_TAB_HH
#define ROBOT_MAP_EDITOR_IO_TAB_HH

#include <ui_robot_map_editor_panel.h>
#include <QTabWidget>

namespace Ui {
    class RobotMapEditorPanelUI;
}

namespace robot_map_editor {
namespace ui {

    class IoTab : QTabWidget{
    Q_OBJECT
    public:
        IoTab(QWidget *parent, model::ArmTrajectoryViewModelPtr viewModel);

        ~IoTab();

    private Q_SLOTS:
        void LoadPcClicked();

        void SaveAsPcClicked();

        void SavePcClicked();
    };

}}
#endif //ROBOT_MAP_EDITOR_IO_TAB_HH
