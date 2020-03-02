# CMake generated Testfile for 
# Source directory: /home/somatic_robot/Development/robot_cleaner_ws/src/robot_map_editor
# Build directory: /home/somatic_robot/Development/robot_cleaner_ws/src/robot_map_editor/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(task_list_control_test "src/qt_tests/task_list_control_test.cc")
set_tests_properties(task_list_control_test PROPERTIES  _BACKTRACE_TRIPLES "/home/somatic_robot/Development/robot_cleaner_ws/src/robot_map_editor/CMakeLists.txt;120;add_test;/home/somatic_robot/Development/robot_cleaner_ws/src/robot_map_editor/CMakeLists.txt;0;")
subdirs("gtest")
subdirs("tests")
