#ifndef ENPM809Y_PROJECT_5_TARGET_H
#define ENPM809Y_PROJECT_5_TARGET_H

#include <iostream>
#include <utility>
#include <memory>
#include <array>
#include <map>
#include "A-Star.h"
#include "MobileRobot_FSM.h"

struct StartingWheeled {
    int x = -1;
    int y = -1;
};
struct StartingTracked {
    int x = -1;
    int y = -1;
};
struct TargetPlate {
    int x = -1;
    int y = -1;
};
struct TargetBottle {
    int x = -1;
    int y = -1;
};

class Target {
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
    char wheeled_target = 'p';
    char tracked_target = 'b';
    std::shared_ptr<MobileRobot> wheeledRobotInMaze = std::make_shared<WheeledRobot>();
    std::shared_ptr<MobileRobot> trackedRobotInMaze = std::make_shared<TrackedRobot>();
};

#endif // ENPM809Y_PROJECT_5_TARGET_H
