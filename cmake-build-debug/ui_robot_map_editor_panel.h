/********************************************************************************
** Form generated from reading UI file 'robot_map_editor_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOT_MAP_EDITOR_PANEL_H
#define UI_ROBOT_MAP_EDITOR_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotMapEditorPanelUI
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *ioTab;
    QVBoxLayout *verticalLayout;
    QGroupBox *PcGrouoBox;
    QGridLayout *gridLayout_3;
    QPushButton *SaveAsPcBtn;
    QPushButton *SavePcBtn;
    QPushButton *LoadPcBtn;
    QPushButton *ClearPcBtn;
    QGroupBox *MeshGroupBox;
    QGridLayout *gridLayout_4;
    QPushButton *SaveAsMeshBtn;
    QPushButton *SaveMeshBtn;
    QPushButton *LoadMeshBtn;
    QPushButton *ClearMeshBtn;
    QWidget *editPcTab;
    QGroupBox *MoveGroupBox;
    QGridLayout *gridLayout_2;
    QPushButton *XPlusPcBtn;
    QLabel *label;
    QPushButton *YPlusPcBtn;
    QDoubleSpinBox *stepSpinBox;
    QPushButton *ZPlusPcBtn;
    QPushButton *XMinusPcBtn;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QPushButton *YMinusPcBtn;
    QPushButton *ZMinusPcBtn;

    void setupUi(QWidget *RobotMapEditorPanelUI)
    {
        if (RobotMapEditorPanelUI->objectName().isEmpty())
            RobotMapEditorPanelUI->setObjectName(QStringLiteral("RobotMapEditorPanelUI"));
        RobotMapEditorPanelUI->resize(449, 556);
        gridLayout = new QGridLayout(RobotMapEditorPanelUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(RobotMapEditorPanelUI);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        ioTab = new QWidget();
        ioTab->setObjectName(QStringLiteral("ioTab"));
        verticalLayout = new QVBoxLayout(ioTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        PcGrouoBox = new QGroupBox(ioTab);
        PcGrouoBox->setObjectName(QStringLiteral("PcGrouoBox"));
        gridLayout_3 = new QGridLayout(PcGrouoBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        SaveAsPcBtn = new QPushButton(PcGrouoBox);
        SaveAsPcBtn->setObjectName(QStringLiteral("SaveAsPcBtn"));

        gridLayout_3->addWidget(SaveAsPcBtn, 0, 1, 1, 1);

        SavePcBtn = new QPushButton(PcGrouoBox);
        SavePcBtn->setObjectName(QStringLiteral("SavePcBtn"));

        gridLayout_3->addWidget(SavePcBtn, 0, 3, 1, 1);

        LoadPcBtn = new QPushButton(PcGrouoBox);
        LoadPcBtn->setObjectName(QStringLiteral("LoadPcBtn"));
        LoadPcBtn->setEnabled(true);

        gridLayout_3->addWidget(LoadPcBtn, 0, 0, 1, 1);

        ClearPcBtn = new QPushButton(PcGrouoBox);
        ClearPcBtn->setObjectName(QStringLiteral("ClearPcBtn"));

        gridLayout_3->addWidget(ClearPcBtn, 1, 1, 1, 1);


        verticalLayout->addWidget(PcGrouoBox);

        MeshGroupBox = new QGroupBox(ioTab);
        MeshGroupBox->setObjectName(QStringLiteral("MeshGroupBox"));
        gridLayout_4 = new QGridLayout(MeshGroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        SaveAsMeshBtn = new QPushButton(MeshGroupBox);
        SaveAsMeshBtn->setObjectName(QStringLiteral("SaveAsMeshBtn"));

        gridLayout_4->addWidget(SaveAsMeshBtn, 0, 1, 1, 1);

        SaveMeshBtn = new QPushButton(MeshGroupBox);
        SaveMeshBtn->setObjectName(QStringLiteral("SaveMeshBtn"));

        gridLayout_4->addWidget(SaveMeshBtn, 0, 3, 1, 1);

        LoadMeshBtn = new QPushButton(MeshGroupBox);
        LoadMeshBtn->setObjectName(QStringLiteral("LoadMeshBtn"));

        gridLayout_4->addWidget(LoadMeshBtn, 0, 0, 1, 1);

        ClearMeshBtn = new QPushButton(MeshGroupBox);
        ClearMeshBtn->setObjectName(QStringLiteral("ClearMeshBtn"));

        gridLayout_4->addWidget(ClearMeshBtn, 1, 1, 1, 1);


        verticalLayout->addWidget(MeshGroupBox);

        tabWidget->addTab(ioTab, QString());
        editPcTab = new QWidget();
        editPcTab->setObjectName(QStringLiteral("editPcTab"));
        MoveGroupBox = new QGroupBox(editPcTab);
        MoveGroupBox->setObjectName(QStringLiteral("MoveGroupBox"));
        MoveGroupBox->setGeometry(QRect(10, 10, 211, 191));
        gridLayout_2 = new QGridLayout(MoveGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        XPlusPcBtn = new QPushButton(MoveGroupBox);
        XPlusPcBtn->setObjectName(QStringLiteral("XPlusPcBtn"));

        gridLayout_2->addWidget(XPlusPcBtn, 2, 2, 1, 1);

        label = new QLabel(MoveGroupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        YPlusPcBtn = new QPushButton(MoveGroupBox);
        YPlusPcBtn->setObjectName(QStringLiteral("YPlusPcBtn"));

        gridLayout_2->addWidget(YPlusPcBtn, 1, 1, 1, 1);

        stepSpinBox = new QDoubleSpinBox(MoveGroupBox);
        stepSpinBox->setObjectName(QStringLiteral("stepSpinBox"));
        stepSpinBox->setValue(0.5);

        gridLayout_2->addWidget(stepSpinBox, 0, 1, 1, 2);

        ZPlusPcBtn = new QPushButton(MoveGroupBox);
        ZPlusPcBtn->setObjectName(QStringLiteral("ZPlusPcBtn"));

        gridLayout_2->addWidget(ZPlusPcBtn, 1, 4, 1, 1);

        XMinusPcBtn = new QPushButton(MoveGroupBox);
        XMinusPcBtn->setObjectName(QStringLiteral("XMinusPcBtn"));

        gridLayout_2->addWidget(XMinusPcBtn, 2, 0, 1, 1);

        label_2 = new QLabel(MoveGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 1, 1, 1);

        label_3 = new QLabel(MoveGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 4, 1, 1);

        line = new QFrame(MoveGroupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 3, 4, 1);

        YMinusPcBtn = new QPushButton(MoveGroupBox);
        YMinusPcBtn->setObjectName(QStringLiteral("YMinusPcBtn"));

        gridLayout_2->addWidget(YMinusPcBtn, 3, 1, 1, 1);

        ZMinusPcBtn = new QPushButton(MoveGroupBox);
        ZMinusPcBtn->setObjectName(QStringLiteral("ZMinusPcBtn"));

        gridLayout_2->addWidget(ZMinusPcBtn, 3, 4, 1, 1);

        tabWidget->addTab(editPcTab, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        retranslateUi(RobotMapEditorPanelUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RobotMapEditorPanelUI);
    } // setupUi

    void retranslateUi(QWidget *RobotMapEditorPanelUI)
    {
        RobotMapEditorPanelUI->setWindowTitle(QApplication::translate("RobotMapEditorPanelUI", "Form", 0));
        PcGrouoBox->setTitle(QApplication::translate("RobotMapEditorPanelUI", "PointCloud", 0));
        SaveAsPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Save as", 0));
        SavePcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Save", 0));
        LoadPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Load", 0));
        ClearPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Clear", 0));
        MeshGroupBox->setTitle(QApplication::translate("RobotMapEditorPanelUI", "Mesh", 0));
        SaveAsMeshBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Save as", 0));
        SaveMeshBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Save", 0));
        LoadMeshBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Load", 0));
        ClearMeshBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "Clear", 0));
        tabWidget->setTabText(tabWidget->indexOf(ioTab), QApplication::translate("RobotMapEditorPanelUI", "IO", 0));
        MoveGroupBox->setTitle(QApplication::translate("RobotMapEditorPanelUI", "Move", 0));
        XPlusPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", ">", 0));
        label->setText(QApplication::translate("RobotMapEditorPanelUI", "Step", 0));
        YPlusPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "^", 0));
        ZPlusPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "^", 0));
        XMinusPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "<", 0));
        label_2->setText(QApplication::translate("RobotMapEditorPanelUI", "   XY", 0));
        label_3->setText(QApplication::translate("RobotMapEditorPanelUI", "    Z", 0));
        YMinusPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "v", 0));
        ZMinusPcBtn->setText(QApplication::translate("RobotMapEditorPanelUI", "V", 0));
        tabWidget->setTabText(tabWidget->indexOf(editPcTab), QApplication::translate("RobotMapEditorPanelUI", "EditPc", 0));
    } // retranslateUi

};

namespace Ui {
    class RobotMapEditorPanelUI: public Ui_RobotMapEditorPanelUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOT_MAP_EDITOR_PANEL_H
