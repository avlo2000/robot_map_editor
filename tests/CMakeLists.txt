include(FindGTest)

find_package(GTest REQUIRED)

enable_testing()

set(SRC
    main.cc
    plan_view_model_TEST.cc
    )

add_executable(robot_map_editor_test ${SRC})

target_link_libraries(robot_map_editor_test
    ${GTEST_BOTH_LIBRARIES}
    ${catkin_LIBRARIES}
    robot_map_editor
    )

target_include_directories(robot_map_editor_test PRIVATE
    ${GTEST_INCLUDE_DIRS}
    ${catkin_INCLUDE_DIRS}
    ${IGNITION-MATH_INCLUDE_DIRS}
    )