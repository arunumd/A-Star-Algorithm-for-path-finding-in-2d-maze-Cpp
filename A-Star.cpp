//
// Created by arunk on 04/27/2019.
//
#include <iostream>
#include <array>
#include <utility>
#include <cmath>
#include "./include/A-Star.h"






void Maze::ModifyMazePosition(int x, int y, char c)
{
    if(grid_[y][x] == '#') {
        std::cout << "Modify maze failed, position blocked!" << std::endl;
        return;
    }
    grid_[y][x] = c;
    return;
}

char Maze::GetMazePosition(int x, int y)
{
    return grid_[y][x];
}

bool Maze::CanMove(int x, int y)
{
    if(grid_[y][x] == '#')
        return false;
    else
        return true;
}


void Maze::Spawn(std::array<std::string, 31> board) const {
    for (auto &item : board) {
        std::cout << item << std::endl;
    }
}


bool Maze::IsTarget(int x, int y, char target_char)
{
    return (grid_[y][x] == target_char);
}


void Maze::SetStartGoal(int start_x, int start_y, int goal_x, int goal_y){
    start_=std::make_pair(start_y, start_x);
    goal_=std::make_pair(goal_y, goal_x);
}


void Maze::ShowMaze()
{
    for(int i = width - 1; i >= 0; i--) {
        if(i >= 10)
            std::cout << i << " ";
        else
            std::cout << i << "  ";
        for(int j = 0; j < length; j++) {
            std::cout << grid_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for(int k = 0; k <= 9; k++) {
        std::cout << k << " ";
    }
    for(int l = 10; l < length; l++) {
        std::cout << l << "";
    }
    std::cout << std::endl;
}



void Maze::ShowStartGoal(){
    std::cout<<"start:"<<start_.first<<"  "<<start_.second<<std::endl;
    std::cout<<"goal:"<<goal_.first<<"  "<< goal_.second<<std::endl;
    
}

// Classes Target and Maze End


const std::pair<int, int> Maze::Scan() const {
    std::cout << "Do you know where is the location of node 'S' ?\n"
                 "Please type 'Y' for Yes and 'N' for No below :\n"
              << std::endl;
    char input = 'A';
    std::cin >> input;
    switch (input) {
        case 'Y':
        case 'y': {
            int z1, z2, temp;
            z1 = -1;
            z2 = -1;
            std::cout << "Please enter the x - coordinate and then the"
                         " y - coordinate for 'S' below" << std::endl;
            while (std::cin >> temp) {
                if (std::cin.fail() || temp < 0 || temp >= grid_.size()) {
                    std::cout << "Please enter valid co-ordinates within"
                                 " the scope of the maze" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                } else if (temp >= 0 && temp < grid_.size()) {
                    if (z1 == -1) z1 = temp;
                    else if (z2 == -1) z2 = temp;
                } else break;
                if (z1 != -1 && z2 != -1 && grid_[z2][z1] != 'S') {
                    std::cout << "'S' was not found in that location" << std::endl;
                    z1 = -1;
                    z2 = -1;
                }
                if (temp != -1 && z1 != -1 && z2 != -1 && grid_[z2][z1] == 'S')
                    break;
            }
            return std::make_pair(z2, z1);
        }
        default: {
            for (int i = 0; i <= 6; i++) {
                for (std::string::size_type j = 0; j < grid_[i].size(); ++j) {
                    if (grid_[i][j] == 'S' || grid_[i][j] == 's') {
                        return std::make_pair(i, j);
                    }
                }
            }
            break;
        }
    }
    return std::make_pair(-1, -1);
}

std::pair<int, int> Maze::North(const std::pair<int, int> node) const {
    return std::make_pair(node.first, node.second + 1);
}

std::pair<int, int> Maze::East(const std::pair<int, int> node) const {
    return std::make_pair(node.first + 1, node.second);
}

std::pair<int, int> Maze::West(const std::pair<int, int> node) const {
    return std::make_pair(node.first - 1, node.second);
}

std::pair<int, int> Maze::South(const std::pair<int, int> node) const {
    return std::make_pair(node.first, node.second - 1);
}

const double Maze::CalculateDistance(std::pair<int, int> current_node) const {
    std::cout<<goal_.first<<"   "<<goal_.second;
    return std::sqrt(std::pow(current_node.first - goal_.first, 2) + \
                     std::pow(current_node.second - goal_.second, 2));
}

bool Maze::IsNotObstacle(std::pair<int, int> node) const {
    if (grid_[node.first][node.second] == '#') return false;
    else return true;
}

bool Maze::IsWithinRegion(std::pair<int, int> node) const {
    if (node.first >= 0 && node.first <= 30 && node.second >= 0 && node.second <= 45) return true;
    else return false;
}

const int Maze::TakeDecision1(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                              const std::pair<int, int> &parent_node, const int &parent_no, int &node_no) {
    if (IsWithinRegion(new_node) && IsNotObstacle(new_node)) {
        info.cost_h = CalculateDistance(new_node);
        info.cost_g = cost_g + 1;
        info.total_cost = info.cost_g + info.cost_h;
        info.node = new_node;
        info.parent = parent_node;
        info.parent_no = parent_no;
        info.node_no = ++node_no;
        priority_list_[info.total_cost] = info;
        open_list_[info.node] = info;
    }
    if (new_node == goal_) {
        closed_list_[new_node] = info;
        return 1;
    } else {
        priority_list_[info.total_cost] = info;
        open_list_[info.node] = info;
        return -1;
    }
}

const int Maze::TakeDecision2(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                              const std::pair<int, int> &parent_node, const int &parent_no, int &node_no) {
    if (IsWithinRegion(new_node) && IsNotObstacle(new_node) &&
        open_list_.find(new_node) != open_list_.end()) { //< If the new node is already there in open and priority lists
        info.cost_h = CalculateDistance(new_node);
        info.cost_g = cost_g + 1;
        info.total_cost = info.cost_g + info.cost_h;
        info.node = new_node;
        info.parent = parent_node;
        info.parent_no = parent_no;
        info.node_no = ++node_no;
        ListInfo value = open_list_.find(new_node)->second;
        if (value.total_cost > info.total_cost) {
            open_list_.find(new_node)->second.cost_g = info.cost_g;
            open_list_.find(new_node)->second.cost_h = info.cost_h;
            open_list_.find(new_node)->second.total_cost = info.total_cost;
            open_list_.find(new_node)->second.parent_no = info.parent_no;
            open_list_.find(new_node)->second.parent = info.parent;
            priority_list_.find(value.total_cost)->second.cost_g = info.cost_g;
            priority_list_.find(value.total_cost)->second.cost_h = info.cost_h;
            priority_list_.find(value.total_cost)->second.total_cost = info.total_cost;
            priority_list_.find(value.total_cost)->second.parent_no = info.parent_no;
            priority_list_.find(value.total_cost)->second.parent = info.parent;
        }
        return -1;
    } else if (IsWithinRegion(new_node) && IsNotObstacle(new_node) &&
               closed_list_.find(new_node) == closed_list_.end()) { //< If the node is not present in closed list
        info.cost_h = CalculateDistance(new_node);
        info.cost_g = cost_g + 1;
        info.total_cost = info.cost_g + info.cost_h;
        info.node = new_node;
        info.parent = parent_node;
        info.parent_no = parent_no;
        info.node_no = ++node_no;
        if (new_node == goal_) {
            closed_list_[new_node] = info;
            return 1;
        } else {
            priority_list_[info.total_cost] = info;
            open_list_[info.node] = info;
            return -1;
        }
    }
    return -1;
}

int Maze::Action() {
    // Initialize cost g, cost h, total cost, node no and parent no for root node
    int node_no = 1;
    int parent_no = 1;
    double cost_h = -100;
    double cost_g = 0;
    std::pair<int, int> parent_node{start_};
    std::pair<int, int> current_node{start_};
    cost_h = CalculateDistance(current_node);
    ListInfo info;
    info.cost_g = cost_g;
    info.cost_h = cost_h;
    info.total_cost = cost_g + cost_h;
    info.parent = current_node;
    info.node = current_node;
    info.node_no = node_no;
    info.parent_no = parent_no;
    // Assume that first node was pushed and popped from priority and open lists
    // Then add it to closed list
    closed_list_[current_node] = info;
    auto north_move = North(current_node);
    const int decision_north1 =
            TakeDecision1(north_move, cost_g, info, parent_node, parent_no, node_no);
    if (decision_north1 == 1) return 1;
    auto south_move = South(current_node);
    const int decision_south1 =
            TakeDecision1(south_move, cost_g, info, parent_node, parent_no, node_no);
    if (decision_south1 == 1) return 1;
    auto east_move = East(current_node);
    const int decision_east1 =
            TakeDecision1(east_move, cost_g, info, parent_node, parent_no, node_no);
    if (decision_east1 == 1) return 1;
    auto west_move = West(current_node);
    const int decision_west1 =
            TakeDecision1(west_move, cost_g, info, parent_node, parent_no, node_no);
    if (decision_west1 == 1) return 1;
    while (current_node != goal_) {
        // Pop the top element from priority list  <---- If priority list empty, then break while loop
        if (priority_list_.empty() && closed_list_.find(goal_) == closed_list_.end()) {
            return -1;
        } else if (priority_list_.empty() && closed_list_.find(goal_) != closed_list_.end()) {
            return 1;
        } else {
            auto low_cost = priority_list_.begin()->first;
            auto low_cost_info = priority_list_.begin()->second;
            priority_list_.erase(priority_list_.begin());
            auto low_cost_node = low_cost_info.node;
            // Remove the same node from open list
            open_list_.erase(low_cost_node);
            closed_list_[low_cost_node] = low_cost_info;
            current_node = low_cost_node;
            parent_node = current_node;
            cost_g = low_cost_info.cost_g;
            parent_no = low_cost_info.node_no;
            north_move = North(current_node);
            const int decision_north2 =
                    TakeDecision2(north_move, cost_g, info, parent_node, parent_no, node_no);
            if (decision_north2 == 1) break;
            south_move = South(current_node);
            const int decision_south2 =
                    TakeDecision2(south_move, cost_g, info, parent_node, parent_no, node_no);
            if (decision_south2 == 1) break;
            east_move = East(current_node);
            const int decision_east2 =
                    TakeDecision2(east_move, cost_g, info, parent_node, parent_no, node_no);
            if (decision_east2 == 1) break;
            west_move = West(current_node);
            const int decision_west2 =
                    TakeDecision2(west_move, cost_g, info, parent_node, parent_no, node_no);
            if (decision_west2 == 1) break;
        }
    }
    return 1;
}

void Maze::PlotTrajectory() {
    int status = Action();
    if (status == 1) {
        auto board = grid_;
        std::pair<int, int> node = goal_;
        std::pair<int, int> parent = closed_list_.find(node)->second.parent;
        while (parent != node) {
            if (node != goal_ || node != start_) {
                board[node.first][node.second] = '+';
            }
            node = closed_list_.find(parent)->second.node;
            parent = closed_list_.find(parent)->second.parent;
        }
        Spawn(board);
    } else { std::cout << "A path could not be found" << std::endl; }
}











// Classes Target and Maze Start




void Target::SetPositions()
{
    int length = tempMaze.length;
    int width = tempMaze.width;
    tempMaze.ShowMaze();
    while(true) {
        std::cout << "Please enter starting point for wheeled robot: x y" << std::endl;
        std::cin >> wheeled.x >> wheeled.y;
        if(wheeled.x >= length or wheeled.x < 0 or wheeled.y >= width or wheeled.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if(tempMaze.CanMove(wheeled.x, wheeled.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    while(true) {
        std::cout << "Please enter starting point for tracked robot: x y" << std::endl;
        std::cin >> tracked.x >> tracked.y;
        if(tracked.x >= length or tracked.x < 0 or tracked.y >= width or tracked.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if(tracked.x == wheeled.x and tracked.y == wheeled.y) {
            std::cout << "Same position with wheeled robot, please try again." << std::endl;
            continue;
        } else if(tempMaze.CanMove(tracked.x, tracked.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    while(true) {
        std::cout << "Please enter location for bottle: x y" << std::endl;
        std::cin >> bottle.x >> bottle.y;
        if(bottle.x >= length or bottle.x < 0 or bottle.y >= width or bottle.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if((bottle.x == tracked.x and bottle.y == tracked.y) or
            (bottle.x == wheeled.x and bottle.y == wheeled.y)) {
            std::cout << "Position occupied, please try again." << std::endl;
            continue;
        } else if(tempMaze.CanMove(bottle.x, bottle.y))
            break;
        else {
            std::cout << "Position is blocked, please try again." << std::endl;
            continue;
        }
    }
    while(true) {
        std::cout << "Please enter location for plate: x y" << std::endl;
        std::cin >> plate.x >> plate.y;
        if(plate.x >= length or plate.x < 0 or plate.y >= width or plate.y < 0) {
            std::cout << "Position out of maze, please try again." << std::endl;
            continue;
        } else if((plate.x == tracked.x and plate.y == tracked.y) or (plate.x == wheeled.x and plate.y == wheeled.y) or
            (plate.x == bottle.x and plate.y == bottle.y)) {
            std::cout << "Position occupied, please try again." << std::endl;
            continue;
        } else if(tempMaze.CanMove(plate.x, plate.y))
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


void Target::AssignTasks(){
     while(true) {
        std::cout << "\nPlease choose target for wheeled robot, plate or the bottle: p/b\n" << std::endl;
        std::cin >> wheeled_target;
        if(wheeled_target == 'P'){
            wheeled_target = 'p';
        }
        if(wheeled_target == 'B'){
            wheeled_target = 'b';
        }
        if(wheeled_target=='p' or wheeled_target=='b'){
            break;
        }
        else{
            std::cout<<"Invalid input, please try again.";
            continue;
        }
    }
    if (wheeled_target == 'p'){
        tracked_target = 'b';
    }
    else {
        tracked_target = 'p';
    }
}


void Target::GoWheeled(){
    if(wheeled_target == 'p'){
        tempMaze.SetStartGoal(wheeled.x, wheeled.y, plate.x, plate.y);
    }
    else {
        tempMaze.SetStartGoal(wheeled.x, wheeled.y, bottle.x, bottle.y);
    }
    tempMaze.Action();
    tempMaze.PlotTrajectory();
    tempMaze.ShowStartGoal();
    tempMaze.ShowMaze();
}
