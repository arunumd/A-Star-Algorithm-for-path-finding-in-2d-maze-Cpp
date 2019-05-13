#include <iostream>
#include <stack>
#include "../include/A-Star.h"
#include "../include/Target.h"
#include "../include/MobileRobot_FSM.h"

int main() {
    Target missions;
    missions.SetPositions();
    missions.AssignTasks();
    missions.GoWheeled();
    missions.GoTracked();
    missions.PlotMaze();
    return 0;
}
