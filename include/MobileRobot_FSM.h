#ifndef ENPM809Y_PROJECT_5_MOBILEROBOT_FSM_H
#define ENPM809Y_PROJECT_5_MOBILEROBOT_FSM_H

#include <iostream>
#include <stack>
#include <string>

class RobotState
{
public:
    virtual void HandleInput(std::stack<RobotState*>&, std::string)
    {
    }
    RobotState(std::string name = "RobotState")
        : name_{ name }
    {
    }
    virtual ~RobotState() = default;

    std::string get_name()
    {
        return name_;
    }
    void show_state()
    {
        std::cout << name_ << std::endl;
        return;
    }

    void set_name(std::string name)
    {
        name_ = name;
    }
    std::string name_;
};

class UpState : public RobotState
{
public:
    UpState()
        : RobotState("Up")
    {
    }
    void HandleInput(std::stack<RobotState*>&, std::string) override;
    ~UpState()
    {
    }
};

class DownState : public RobotState
{
public:
    DownState()
        : RobotState("Down")
    {
    }
    void HandleInput(std::stack<RobotState*>&, std::string) override;
    ~DownState()
    {
    }
};

class LeftState : public RobotState
{
public:
    LeftState()
        : RobotState("Left")
    {
    }
    void HandleInput(std::stack<RobotState*>&, std::string) override;
    ~LeftState()
    {
    }
};

class RightState : public RobotState
{
public:
    RightState()
        : RobotState("Right")
    {
    }
    void HandleInput(std::stack<RobotState*>&, std::string) override;
    ~RightState()
    {
    }
};

class MobileRobot
{
public:
    MobileRobot() = default;
    MobileRobot(std::string RobotName);
    ~MobileRobot() = default;
    std::string name;
    virtual void PrintInfo();
    std::stack<RobotState*> RobotStack_;
    virtual void HandleInput(std::string input);
    std::stack<RobotState*> get_stack()
    {
        return RobotStack_;
    }
    void ShowStack();
};

class WheeledRobot : public MobileRobot
{
public:
    WheeledRobot()
        : MobileRobot("Wheeled Robot"){};
    ~WheeledRobot() = default;
    void PrintInfo() override;
};

class TrackedRobot : public MobileRobot
{
public:
    TrackedRobot()
        : MobileRobot("Tracked Robot"){};
    ~TrackedRobot() = default;
    void PrintInfo() override;
};

#endif // MOBILEROBOT_FSM_H
