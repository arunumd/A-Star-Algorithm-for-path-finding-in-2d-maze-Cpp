#ifndef ENPM809Y_PROJECT_5_MOBILEROBOT_FSM_H
#define ENPM809Y_PROJECT_5_MOBILEROBOT_FSM_H

#include <iostream>
#include <stack>
#include <string>

class RobotState {
public:
    virtual void HandleInput(std::stack<RobotState *> &, std::string) {
    }

    explicit RobotState(std::string name = "RobotState"): name_{name} {}

    virtual ~RobotState() = default;

    std::string get_name() {return name_;}

    std::string name_;
};

class UpState : public RobotState {
public:
    UpState(): RobotState("Up") {}

    void HandleInput(std::stack<RobotState *> &, std::string) override;

    ~UpState() override = default;
};

class DownState : public RobotState {
public:
    DownState(): RobotState("Down") {}

    void HandleInput(std::stack<RobotState *> &, std::string) override;

    ~DownState() override = default;
};

class LeftState : public RobotState {
public:
    LeftState(): RobotState("Left") {
    }

    void HandleInput(std::stack<RobotState *> &, std::string) override;

    ~LeftState() override = default;
};

class RightState : public RobotState {
public:
    RightState(): RobotState("Right") {}

    void HandleInput(std::stack<RobotState *> &, std::string) override;

    ~RightState() override = default;
};

class MobileRobot {
public:
    MobileRobot() = default;

    explicit MobileRobot(std::string RobotName);

    ~MobileRobot() = default;

    std::string name;
    std::stack<RobotState *> RobotStack_;

    virtual void HandleInput(std::string input);

    void ShowStack();
};

class WheeledRobot : public MobileRobot {
public:
    WheeledRobot(): MobileRobot("Wheeled Robot") {};

    ~WheeledRobot() = default;
};

class TrackedRobot : public MobileRobot {
public:
    TrackedRobot(): MobileRobot("Tracked Robot") {};

    ~TrackedRobot() = default;
};

#endif // MOBILEROBOT_FSM_H
