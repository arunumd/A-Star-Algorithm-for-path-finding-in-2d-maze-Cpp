// Classes Target and Maze Start
#include <array>
#include <cmath>
#include <iostream>
#include <utility>
#include <memory>
#include "../include/A-Star.h"
#include "../include/Target.h"

void Target::SetPositions() {
    int length = tempMaze.length;
    int width = tempMaze.width;
    tempMaze.ShowMaze();
    while (true) {
        std::cout << "Please enter starting point for wheeled robot: x y" << std::endl;
        std::cin >> wheeled.x >> wheeled.y;
        if (wheeled.x >= length or wheeled.x < 0 or wheeled.y >= width or wheeled.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if (tempMaze.CanMove(wheeled.x, wheeled.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    while (true) {
        std::cout << "Please enter starting point for tracked robot: x y" << std::endl;
        std::cin >> tracked.x >> tracked.y;
        if (tracked.x >= length or tracked.x < 0 or tracked.y >= width or tracked.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if (tracked.x == wheeled.x and tracked.y == wheeled.y) {
            std::cout << "Same position with wheeled robot, please try again." << std::endl;
            continue;
        } else if (tempMaze.CanMove(tracked.x, tracked.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    while (true) {
        std::cout << "Please enter location for bottle: x y" << std::endl;
        std::cin >> bottle.x >> bottle.y;
        if (bottle.x >= length or bottle.x < 0 or bottle.y >= width or bottle.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if ((bottle.x == tracked.x and bottle.y == tracked.y) or
                   (bottle.x == wheeled.x and bottle.y == wheeled.y)) {
            std::cout << "Position occupied, please try again." << std::endl;
            continue;
        } else if (tempMaze.CanMove(bottle.x, bottle.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    while (true) {
        std::cout << "Please enter location for plate: x y" << std::endl;
        std::cin >> plate.x >> plate.y;
        if (plate.x >= length or plate.x < 0 or plate.y >= width or plate.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if ((plate.x == tracked.x and plate.y == tracked.y) or
                   (plate.x == wheeled.x and plate.y == wheeled.y) or
                   (plate.x == bottle.x and plate.y == bottle.y)) {
            std::cout << "Position occupied, please try again." << std::endl;
            continue;
        } else if (tempMaze.CanMove(plate.x, plate.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    tempMaze.ModifyMazePosition(tracked.x, tracked.y, 't');
    tempMaze.ModifyMazePosition(wheeled.x, wheeled.y, 'w');
    tempMaze.ModifyMazePosition(bottle.x, bottle.y, 'b');
    tempMaze.ModifyMazePosition(plate.x, plate.y, 'p');
    tempMaze.ShowMaze();
}

void Target::AssignTasks() {
    while (true) {
        std::cout << "\nPlease choose target for wheeled robot, plate or the bottle: p/b\n" << std::endl;
        std::cin >> wheeled_target;
        if (wheeled_target == 'P') {
            wheeled_target = 'p';
        }
        if (wheeled_target == 'B') {
            wheeled_target = 'b';
        }
        if (wheeled_target == 'p' or wheeled_target == 'b') {
            break;
        } else {
            std::cout << "Invalid input, please try again.";
            continue;
        }
    }
    if (wheeled_target == 'p') {
        tracked_target = 'b';
    } else {
        tracked_target = 'p';
    }
}

void Target::GoWheeled() {
    if (wheeled_target == 'p') {
        wheeledMaze.SetStartGoal(wheeled.x, wheeled.y, plate.x, plate.y);
    } else {
        wheeledMaze.SetStartGoal(wheeled.x, wheeled.y, bottle.x, bottle.y);
    }
    wheeledMaze.Action();
    wheeledMaze.PlotTrajectory('|');
    wheeledMaze.ModifyMazePosition(wheeled.x, wheeled.y, 't');
    if (wheeled_target == 'p') {
        wheeledMaze.ModifyMazePosition(plate.x, plate.y, 'p');
    } else {
        wheeledMaze.ModifyMazePosition(bottle.x, bottle.y, 'b');
    }
    wheeledMaze.ShowMaze();
    wheeledMaze.BuildStack(wheeledRobotInMaze);
    wheeledRobotInMaze->ShowStack();
}

void Target::GoTracked() {
    if (tracked_target == 'p') {
        trackedMaze.SetStartGoal(tracked.x, tracked.y, plate.x, plate.y);
    } else {
        trackedMaze.SetStartGoal(tracked.x, tracked.y, bottle.x, bottle.y);
    }
    trackedMaze.Action();
    trackedMaze.PlotTrajectory('-');
    trackedMaze.ModifyMazePosition(tracked.x, tracked.y, 't');
    if (tracked_target == 'p') {
        trackedMaze.ModifyMazePosition(plate.x, plate.y, 'p');
    } else {
        trackedMaze.ModifyMazePosition(bottle.x, bottle.y, 'b');
    }
    trackedMaze.ShowMaze();
    trackedMaze.BuildStack(trackedRobotInMaze);
    trackedRobotInMaze->ShowStack();
}

void Target::PlotMaze() {
    for (int j = tempMaze.width - 1; j >= 0; j--) {
        for (int i = 0; i < tempMaze.length; i++) {
            if (wheeledMaze.GetMazePosition(i, j) == '|' and trackedMaze.GetMazePosition(i, j) == '-') {
                tempMaze.ModifyMazePosition(i, j, '+');
            } else if (wheeledMaze.GetMazePosition(i, j) == '|') {
                tempMaze.ModifyMazePosition(i, j, '|');
            } else if (trackedMaze.GetMazePosition(i, j) == '-') {
                tempMaze.ModifyMazePosition(i, j, '-');
            }
        }
    }
    tempMaze.ModifyMazePosition(bottle.x, bottle.y, 'b');
    tempMaze.ModifyMazePosition(plate.x, plate.y, 'p');
    tempMaze.ModifyMazePosition(wheeled.x, wheeled.y, 'w');
    tempMaze.ModifyMazePosition(tracked.x, tracked.y, 't');
    tempMaze.ShowMaze();
    std::cout << std::endl;
}
