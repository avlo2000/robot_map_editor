//
// Created by Alex on 10/02/20.
//

#include <gtest/gtest.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "testing_node");
    ros::NodeHandle nh;
    ROS_ERROR("Waiting for attach!");
    std::cin.get();
    return RUN_ALL_TESTS();
}