//
// Created by arunk on 04/27/2019.
//

#ifndef ENPM809Y_PROJECT_5_A_STAR_H
#define ENPM809Y_PROJECT_5_A_STAR_H

#include <iostream>
#include <utility>
#include <array>
#include <map>
#include <stack>
#include <memory>
#include "../include/MobileRobot_FSM.h"

struct ListInfo {
    double cost_g = 0;
    double cost_h = -10;
    double total_cost = -10;
    std::pair<int, int> node{std::make_pair(-100, -100)};
    std::pair<int, int> parent{std::make_pair(-100, -100)};
};

class Maze {
public:
    Maze() : grid_{{"######################  ######################",
                    "#        #           #  #                    #",
                    "#  ####  #  #######  #  ##########  #######  #",
                    "#  #     #  #        #        #     #     #  #",
                    "#  ####  #  ################  #  #######  #  #",
                    "#     #  #                 #  #  #        #  #",
                    "#  #  #  #  #############  #  #  #  ####  #  #",
                    "#  #  #  #  #           #  #  #  #  #  #  #  #",
                    "#  #  #  #  #  #######  #  #  #  #  #  #  #  #",
                    "#  #  #  #  #  #     #  #  #  #  #  #     #  #",
                    "#  #  #  #  #  #######  #  #  #  #  #######  #",
                    "#  #  #  #  #  #        #  #  #  #           #",
                    "####  #  #  ##########  #  #  #  #############",
                    "#     #  #              #  #  #              #",
                    "#  #  #  #######  ####  #  #  #  ##########  #",
                    "#  #  #     #     #     #  #  #     #     #  #",
                    "#  #  ####  #############  #  ####  #  #  #  #",
                    "#  #  #                    #     #     #  #  #",
                    "####  #  ######################  ##########  #",
                    "#     #  #                    #              #",
                    "#  ####  #  ################  #############  #",
                    "#  #     #  #              #           #  #  #",
                    "#  #  ####  #  ##########  #  #  ####  #  #  #",
                    "#  #  #  #  #  #  #     #  #  #  #        #  #",
                    "#  #  #  #  #  #  #######  #  #############  #",
                    "#  #     #  #           #  #                 #",
                    "#  #######  #############  ###################",
                    "#           #                 #        #     #",
                    "#  ##########  #############  #######  ####  #",
                    "#              #                             #",
                    "##############################################"}},
             start_{std::make_pair(-1, -1)}, goal_{std::make_pair(-1, -1)} {}

    ~Maze() = default;

    bool CanMove(int x, int y);

    int width = 31;
    int length = 46;

    void ShowMaze();

    char GetMazePosition(int x, int y);

    void ModifyMazePosition(int x, int y, char c);

    void SetStartGoal(int start_x, int start_y, int goal_x, int goal_y);

    void BuildStack(const std::shared_ptr<MobileRobot> &robot_in_maze);

    std::pair<int, int> North(std::pair<int, int> node) const;

    std::pair<int, int> East(std::pair<int, int> node) const;

    std::pair<int, int> West(std::pair<int, int> node) const;

    std::pair<int, int> South(std::pair<int, int> node) const;

    const int TakeDecision1(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                            const std::pair<int, int> &parent_node);

    const int TakeDecision2(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                            const std::pair<int, int> &parent_node);

    int Action();

    const double CalculateDistance(std::pair<int, int> current_node) const;

    bool IsNotObstacle(std::pair<int, int> node) const;

    bool IsWithinRegion(std::pair<int, int> node) const;

    void PlotTrajectory(char path_icon);

    std::array<std::string, 31> grid_;

private:
    std::pair<int, int> start_, goal_;
    std::multimap<double, ListInfo> priority_list_;
    std::map<std::pair<int, int>, ListInfo> open_list_, closed_list_;
};

#endif //ENPM809Y_PROJECT_5_A_STAR_H
