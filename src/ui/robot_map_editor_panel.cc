//
// Created by Denys Kotelovych on 1/14/19.
//

#include <ros/ros.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

#include <robot_map_editor/ui/robot_map_editor_panel.hh>
#include <pcl/io/boost.h>
#include "ui_robot_map_editor_panel.h"
#include <robot_cleaner_core/utils/params_provider/parameters_wrapper.hh>
#include <ros/package.h>

static const std::int32_t kUpdateIntervalMiliseconds = 20;

namespace robot_map_editor {
namespace ui {

RobotMapEditorPanel::RobotMapEditorPanel(QWidget *parent)
        : rviz::Panel(parent),
          ui_(new Ui::RobotMapEditorPanelUI()),
          viewModelPtr_(new model::PointCloudViewModel){
    ui_->setupUi(this);

    updateTimer_ = new QTimer;

    connect(updateTimer_, SIGNAL(timeout()), this, SLOT(OnUpdate()));
    connect(ui_->LoadPcBtn, SIGNAL(released()), this, SLOT(LoadPcButtonClicked()));
}

RobotMapEditorPanel::~RobotMapEditorPanel() {
    delete ui_;
    updateTimer_->stop();
    delete updateTimer_;
}

void RobotMapEditorPanel::onInitialize() {
    ROS_DEBUG_STREAM_NAMED("RobotMapEditor", "RobotMapEditorPanel::onInitialize");

    updateTimer_->start(kUpdateIntervalMiliseconds);
    InitResources();
    InitControls();
    InitControllers();
}

void RobotMapEditorPanel::LoadPcButtonClicked() {
    QString fileName = QFileDialog::getOpenFileName(
            this, tr("Load PointCloud file"), QString::fromStdString(""), tr("PointCloud (*.ply);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    viewModelPtr_->Load(fileName.toStdString());
    viewModelPtr_->Subtract({0, 0, 0}, 1);
}

void RobotMapEditorPanel::OnUpdate() {
}

void RobotMapEditorPanel::InitControllers() {
    ogreControllerPtr_.reset(new controllers::OgreController(vis_manager_, *viewModelPtr_));
}

void RobotMapEditorPanel::InitResourcesInternal(std::string path) {
    Ogre::ResourceGroupManager::getSingleton().addResourceLocation(path, "FileSystem", "map_editor", true);
    ROS_INFO_STREAM_NAMED("robot_map_editor_panel", "loading ogre resources from: " << path);

    for ( boost::filesystem::recursive_directory_iterator end, dir(path);dir != end; ++dir ){
        if (boost::filesystem::is_directory(dir->path())){
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(dir->path().string(), "FileSystem", "map_editor", true);
            ROS_INFO_STREAM_NAMED("robot_map_editor_panel", "loading ogre resources from: " << dir->path().string());
        }
    }
}

void RobotMapEditorPanel::InitResources() {
    Ogre::ResourceGroupManager::getSingletonPtr()->createResourceGroup("map_editor");

    std::string path = ros::package::getPath("robot_map_editor") + "/ogre_media/";
    InitResourcesInternal(path);
    std::string stlPath = robot_cleaner_core::utils::parameters::ParametersWrapper::getMapsDir();
    InitResourcesInternal(stlPath);

    Ogre::ResourceGroupManager::getSingletonPtr()->initialiseResourceGroup("map_editor");
    Ogre::ResourceGroupManager::getSingletonPtr()->loadResourceGroup("map_editor");
}

void RobotMapEditorPanel::InitControls(){
}

}
}

#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(robot_map_editor::ui::RobotMapEditorPanel, rviz::Panel)
