cmake_minimum_required(VERSION 3.2)
project(robot_map_editor)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    geometry_msgs
    moveit_ros_planning
    moveit_ros_planning_interface
    moveit_ros_visualization
    moveit_visual_tools
    pcl_conversions
    pcl_ros
    pluginlib
    roscpp
    rviz
    std_msgs
    tf
    rviz_vive_plugin_msgs
    rviz_vr
    robot_cleaner_action_msgs
    robot_cleaner_core
    )

find_package(Qt5 ${rviz_QT_VERSION} EXACT REQUIRED Core Widgets)

enable_testing(true)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Test REQUIRED)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    robot_map_editor
  CATKIN_DEPENDS
    geometry_msgs
    moveit_ros_planning
    moveit_ros_planning_interface
    moveit_ros_visualization
    moveit_visual_tools
    pcl_conversions
    pcl_ros
    pluginlib
    roscpp
    rviz
    std_msgs
    tf
    rviz_vive_plugin_msgs
    rviz_vr
    somatic_utils
    robot_cleaner_action_msgs
    somatic_rviz_wrapper
    )

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}

    )

set(QT_LIBRARIES Qt5::Widgets Qt5::Test)

add_definitions(-DQT_NO_KEYWORDS)
add_definitions(-DLINUX -DPOSIX)

link_directories(
    ${catkin_LIBRARY_DIRS})

qt5_wrap_cpp(MOC_FILES
    # Main
        include/robot_map_editor/ui/robot_map_editor_panel.hh
    # Tests

    # Dialogs

    # Controls

    # ArmTrajectory

    OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED -DBOOST_LEXICAL_CAST_INCLUDED
    )

qt5_wrap_ui(UIC_FILES
    # Main
    ui/robot_map_editor_panel.ui

    # Dialogs

    # ArmTrajectory

    # Controls
    )

add_library(robot_map_editor
    ${MOC_FILES}
    ${UIC_FILES}

    src/model/point_cloud_view_model.cc
    src/model/mesh_view_model.cc

    src/controllers/ogre_controller.cc

    src/utils/ogre_visualisation.cc
    src/ogre_helpers/map_point_cloud.cc

    src/utils/history.cc
    src/utils/pcl_to_eigen.cc

    src/ogre_helpers/object_list.cc
    src/ogre_helpers/ogre_visuals.cc

    src/ui/io_tab.cc
    src/ui/edit_pc_tab.cc
    src/ui/robot_map_editor_panel.cc
    )

target_link_libraries(robot_map_editor
    ${QT_LIBRARIES}
    ${catkin_LIBRARIES}
    Qt5::Test
    )

add_executable(to_build src/utils/to_build.cc)
target_link_libraries(to_build
        ${PROJECT_NAME}
        ${catkin_LIBRARIES})

add_test(task_list_control_test src/qt_tests/task_list_control_test.cc)
add_subdirectory(tests)