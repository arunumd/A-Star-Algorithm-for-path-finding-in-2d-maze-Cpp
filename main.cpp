#include <iostream>
#include "./include/A-Star.h"
#include "./include/Target.h"
#include <stack>
#include "./include/MobileRobot_FSM.h"

int main() {
//    Maze game;
//    game.Scan();
//    game.Action();
//    game.PlotTrajectory();
    
    
    Target missions;
    missions.SetPositions();
    missions.AssignTasks();
    missions.GoWheeled();
    missions.GoTracked();
    missions.PlotMaze();
    return 0;
}