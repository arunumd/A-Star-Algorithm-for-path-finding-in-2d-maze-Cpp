[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
# Path-finding in 2d maze for two mobile robots using A-Star algorithm

This repository contains source code for ENPM809Y final project on search algorithm for autonomous robots moving on a 2d maze. The source code is in C++ 11. The maze will printed on the terminal and the user shall be prompted to enter the locations of two robots and also two targets. Later, the user will be asked to assign task for one of the robots. The other robot automatically assigned the unassigned task. The two robots complete the navigation task using an A* algorithm.

# Assumptions

 - You have a C++ 11 compatible compiler
 - You have a Mac/ Windows/ Ubuntu operating system
 - You have CMake version 3.13 (minimum)
 - You have git installed on your machine

# Build and Run

In order to run the project, do the following in a new terminal :

```
git clone https://github.com/nuclearczy/ENPM809Y-Final-Project.git
cd ENPM809Y-Final-Project
mkdir build
cd build
cmake.. && make
./ENPM809Y-Final-Project
```

After these please follow on-screen instructions

# Results

![Result from our algorithm](https://github.com/nuclearczy/ENPM809Y-Final-Project/blob/master/results/output.png)

# UML Class Diagram

![UML Class Diagram for the Project](https://github.com/nuclearczy/ENPM809Y-Final-Project/blob/master/UML%20Diagrams/UML%20Class%20Diagrams/UML%20Class%20Diagram.jpg)

# UML Activity Diagrams

**Complete Project Pipeline**

![UML Activity Diagram for the Project](https://github.com/nuclearczy/ENPM809Y-Final-Project/blob/master/UML%20Diagrams/UML%20Activity%20Diagrams/UML%20Activity%20Diagram%20-%20Full%20Project.jpg)

**A - Star Algorithm Pipeline**
![UML Activity Diagram for A - Star Algorithm](https://github.com/nuclearczy/ENPM809Y-Final-Project/blob/master/UML%20Diagrams/UML%20Activity%20Diagrams/UML%20Activity%20Diagram%20-%20A-Star%20Algorithm.jpg)
