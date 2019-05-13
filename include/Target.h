/*
 * @file        Target.h
 * @author      Arun Kumar Devarajulu
 * @author      Zuyang Cao
 * @author      Qidi Xu
 * @author	    Hongyang Jiang
 * @date        05/07/2019
 * @brief       The file Target.h contains the header declarations for Target
 *              class. The class will be used for implementation of user interface,
 *              visualization etc in Final Project
 * @license     MIT License
 *              Permission is hereby granted, free of charge, to any person obtaining a copy
 *              of this software and associated documentation files (the "Software"), to deal
 *              in the Software without restriction, including without limitation the rights
 *              to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *              copies of the Software, and to permit persons to whom the Software is
 *              furnished to do so, subject to the following conditions:
 *
 *              The above copyright notice and this permission notice shall be included in all
 *              copies or substantial portions of the Software.
 *
 *              THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *              IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *              FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *              AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *              LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *              OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *              SOFTWARE.
 */

#ifndef ENPM809Y_PROJECT_5_TARGET_H
#define ENPM809Y_PROJECT_5_TARGET_H

#include <iostream>
#include <utility>
#include <memory>
#include <array>
#include <map>
#include "A-Star.h"
#include "MobileRobot_FSM.h"

/*
@brief Define data structure that contain coordinate for wheeled robot
*/
struct StartingWheeled {
    int x = -1;
    int y = -1;
};

/*
@brief Define data structure that contain coordinate for tracked robot
*/
struct StartingTracked {
    int x = -1;
    int y = -1;
};

/*
@brief Define data structure that contain coordinate for plate
*/
struct TargetPlate {
    int x = -1;
    int y = -1;
};

/*
@brief Define data structure that contain coordinate for bottle
*/
struct TargetBottle {
    int x = -1;
    int y = -1;
};

class Target {
public:
    /*
	@brief  Define default constructor
	*/
    Target() = default;

    /*
	@brief  Define default constructor
	*/
    ~Target() = default;

    /*
	@brief Asks user for tracked, wheeled robot starting point
	and plate, bottle goal point. Input check will be conducted
	to see if the given node is out of maze or blocked
	*/
    void SetPositions();

    /*
	@brief Assign task for tracked and wheeled robot to pick up
	plant and bottle
	*/
    void AssignTasks();

    /*
	@brief Initiates A* algorithm for wheeled robot and show the result
	*/
    void GoWheeled();

    /*
	@brief Initiates A* algorithm for wheeled robot and show the result
	*/
    void GoTracked();

    /*
	@brief Plot maze with two paths found
	*/
    void PlotMaze();

    /*
	@brief Creates object wheeled for StartingWheeled class
	*/
    StartingWheeled wheeled;

    /*
	@brief Creates object tracked for StartingTracked class
	*/
    StartingTracked tracked;

    /*
	@brief Creates object plate for TargetPlate class
	*/
    TargetPlate plate;

    /*
	@brief Creates object bottle for TargetBottle class
	*/
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
