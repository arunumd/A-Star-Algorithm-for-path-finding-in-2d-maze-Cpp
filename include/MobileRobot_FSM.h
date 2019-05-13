/*
 * @file        MobileRobot_FSM.h
 * @author      Arun Kumar Devarajulu
 * @author      Zuyang Cao
 * @author      Qidi Xu
 * @author	    Hongyang Jiang
 * @date        05/10/2019
 * @brief       The file MobileRobot_FSM.h contains the header declarations for RobotState
 *              and class. The class will be used for implementation of finite state machine
 *              in Final Project
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
 *              FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 *              AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *              LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *              OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *              SOFTWARE.
 */

#ifndef ENPM809Y_PROJECT_5_MOBILEROBOT_FSM_H
#define ENPM809Y_PROJECT_5_MOBILEROBOT_FSM_H

#include <iostream>
#include <stack>
#include <string>

class RobotState {
public:
    /*
	@brief Process input and move the robot to the next node according to the given RobotState
	class
	@param string - sequence of move instruction
	@param stack - address of stack to gain access to the value while out of scope
	*/
    virtual void HandleInput(std::stack<RobotState *> &, std::string) {
    }

    /*
     * @brief
     * @param name_ - name of RobotState
     * @param stack - address of stack to gain access to the value while out of scope
     * */
    explicit RobotState(std::string name = "RobotState"): name_{name} {}

    /*
	@brief Define default destructor
	*/
    virtual ~RobotState() = default;

    /*
	@brief Get name value as string
	@param name of RobotState
	@return name of RobotState as string
	*/
    std::string get_name() {return name_;}

    /*
	@brief Define the storage for name of RobotState
	*/
    std::string name_;
};

class UpState : public RobotState {
public:
    /*
	@brief Inheritance UpState from RobotState
	*/
    UpState(): RobotState("Up") {}

    /*
	@brief Push current node location into stack while update the new node
	according to the previous move
	*/
    void HandleInput(std::stack<RobotState *> &, std::string) override;

    /*@brief Default destructor*/
    ~UpState() override = default;
};

class DownState : public RobotState {
public:
    /*
	@brief Inheritance DownState from RobotState
	*/
    DownState(): RobotState("Down") {}

    /*
	@brief Push current node location into stack while update the new node
	according to the previous move
	*/
    void HandleInput(std::stack<RobotState *> &, std::string) override;

    /*@brief Default destructor*/
    ~DownState() override = default;
};

class LeftState : public RobotState {
public:
    /*
	@brief Inheritance LeftState from RobotState
	*/
    LeftState(): RobotState("Left") {}

    /*
	@brief Push current node location into stack while update the new node
	according to the previous move
	*/
    void HandleInput(std::stack<RobotState *> &, std::string) override;

    /*@brief Default destructor*/
    ~LeftState() override = default;
};

class RightState : public RobotState {
public:
    /*
	@brief Inheritance RightState from RobotState
	*/
    RightState(): RobotState("Right") {}

    /*
	@brief Push current node location into stack while update the new node
	according to the previous move
	*/
    void HandleInput(std::stack<RobotState *> &, std::string) override;

    /*@brief Default destructor*/
    ~RightState() override = default;
};

class MobileRobot {
public:
    /*
	@brief Default constructor
	*/
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
    /*
	@brief Default constructor
	*/
    WheeledRobot(): MobileRobot("Wheeled Robot") {};

    /* @brief Default destructor*/
    ~WheeledRobot() = default;
};

class TrackedRobot : public MobileRobot {
public:
    /*
	@brief Default constructor
	*/
    TrackedRobot(): MobileRobot("Tracked Robot") {};

    /* @brief Default destructor*/
    ~TrackedRobot() = default;
};

#endif // MOBILEROBOT_FSM_H
