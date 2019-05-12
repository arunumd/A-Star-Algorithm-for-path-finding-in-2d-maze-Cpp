#ifndef ENPM809Y_PROJECT_5_TARGET_H
#define ENPM809Y_PROJECT_5_TARGET_H
#include <iostream>
#include <utility>
#include <array>
#include <map>
#include "A-Star.h"



struct StartingWheeled {
    int x;
    int y;
};
struct StartingTracked {
    int x;
    int y;
};
struct TargetPlate {
    int x;
    int y;
};
struct TargetBottle {
    int x;
    int y;
};




class Target
{
public:
    Target() = default;
    ~Target() = default;
    void SetPositions();
    void AssignTasks();
    void GoWheeled();
    void GoTracked();
    void PlotMaze();
    
    StartingWheeled wheeled;
    StartingTracked tracked;
    TargetPlate plate;
    TargetBottle bottle;
private:
    Maze tempMaze;
    Maze wheeledMaze;
    Maze trackedMaze;
    MobileRobot *wheeledRobotInMaze = new WheeledRobot();
    MobileRobot *trackedRobotInMaze = new TrackedRobot();
    char wheeled_target='p';
    char tracked_target='b';
};


#endif // ENPM809Y_PROJECT_5_TARGET_H
