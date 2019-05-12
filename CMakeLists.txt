cmake_minimum_required(VERSION 3.13)
project(Final_Version_809Y_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final_Version_809Y_Project app/A-Star.cpp app/MobileRobot_FSM.cpp app/Target.cpp
        app/main.cpp include/A-Star.h include/MobileRobot_FSM.h include/Target.h)