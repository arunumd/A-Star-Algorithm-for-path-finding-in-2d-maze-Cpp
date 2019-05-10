#include <iostream>
#include "./include/A-Star.h"

int main() {
//    Maze game;
//    game.Scan();
//    game.Action();
//    game.PlotTrajectory();
    
    
    Target missions;
    missions.SetPositions();
    missions.AssignTasks();
    missions.GoWheeled();
    

    return 0;
}