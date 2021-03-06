#include <iostream>
#include <stack>
#include <string>
#include "../include/MobileRobot_FSM.h"

MobileRobot::MobileRobot(std::string RobotName) {
    name = std::move(RobotName);
}

void MobileRobot::HandleInput(const std::string input) {
    RobotState *state = new UpState();

    if (RobotStack_.empty())
        state->HandleInput(RobotStack_, input);
    else
        RobotStack_.top()->HandleInput(RobotStack_, input);
    delete state;
}

void MobileRobot::ShowStack() {
    auto s = RobotStack_;
    while (s.size() > 1) {
        printf("%s\n", s.top()->get_name().c_str());
        s.pop();
    }
    printf("\n");
}

std::string MobileRobot::GetName(){
    return name;
}

// UpState::UpState()

void UpState::HandleInput(std::stack<RobotState *> &stack_, std::string input) {
    if (stack_.empty()) {
        stack_.push(this);
    }
    if (input == "UP") {
        RobotState *UP_PTR = new UpState();
        stack_.push(UP_PTR);
    }
    if (input == "DOWN") {
        RobotState *DOWN_PTR = new DownState();
        stack_.push(DOWN_PTR);
    }
    if (input == "LEFT") {
        RobotState *LEFT_PTR = new LeftState();
        stack_.push(LEFT_PTR);
    }
    if (input == "RIGHT") {
        RobotState *RIGHT_PTR = new RightState();
        stack_.push(RIGHT_PTR);
    }
}

void DownState::HandleInput(std::stack<RobotState *> &stack_, std::string input) {
    if (stack_.empty()) {
        stack_.push(this);
    }
    if (input == "UP") {
        RobotState *UP_PTR = new UpState();
        stack_.push(UP_PTR);
    }
    if (input == "DOWN") {
        RobotState *DOWN_PTR = new DownState();
        stack_.push(DOWN_PTR);
    }
    if (input == "LEFT") {
        RobotState *LEFT_PTR = new LeftState();
        stack_.push(LEFT_PTR);
    }
    if (input == "RIGHT") {
        RobotState *RIGHT_PTR = new RightState();
        stack_.push(RIGHT_PTR);
    }
}

void LeftState::HandleInput(std::stack<RobotState *> &stack_, std::string input) {
    if (stack_.empty()) {
        stack_.push(this);
    }
    if (input == "UP") {
        RobotState *UP_PTR = new UpState();
        stack_.push(UP_PTR);
    }
    if (input == "DOWN") {
        RobotState *DOWN_PTR = new DownState();
        stack_.push(DOWN_PTR);
    }
    if (input == "LEFT") {
        RobotState *LEFT_PTR = new LeftState();
        stack_.push(LEFT_PTR);
    }
    if (input == "RIGHT") {
        RobotState *RIGHT_PTR = new RightState();
        stack_.push(RIGHT_PTR);
    }
}

void RightState::HandleInput(std::stack<RobotState *> &stack_, std::string input) {
    if (stack_.empty()) {
        stack_.push(this);
    }
    if (input == "UP") {
        RobotState *UP_PTR = new UpState();
        stack_.push(UP_PTR);
    }
    if (input == "DOWN") {
        RobotState *DOWN_PTR = new DownState();
        stack_.push(DOWN_PTR);
    }
    if (input == "LEFT") {
        RobotState *LEFT_PTR = new LeftState();
        stack_.push(LEFT_PTR);
    }
    if (input == "RIGHT") {
        RobotState *RIGHT_PTR = new RightState();
        stack_.push(RIGHT_PTR);
    }
}
