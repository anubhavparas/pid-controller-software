# Acme Robotics PID Controller
[![Build Status](https://app.travis-ci.com/anubhavparas/pid-controller-software.svg?branch=main)](https://app.travis-ci.com/anubhavparas/pid-controller-software)
[![Coverage Status](https://coveralls.io/repos/github/anubhavparas/pid-controller-software/badge.svg?branch=main)](https://coveralls.io/github/anubhavparas/pid-controller-software?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---

Authors: 
- Part 1: Design:
    - Driver: [Anubhav Paras](<https://github.com/anubhavparas>)
    - Navigator: [Charu Sharma](<https://github.com/Sharma117555448>)
- Part 2: Implementation:
    - Driver: Shon Cortes
    - Navigator: Arunava Basu

## Overview

Acme Robotics needs a PID Controller software for the new mobile robot development project. This project develops a library for the PID controller. 

The following are the proposed designs for the controller: 

![alt text](./docs/images/pid_class_diagram.png?raw=true "PID Controller")

Flow diagrams can be found [here](./docs/images/).

-----
### Implementation Instructions:
<details>
<summary><strong>TODO</strong></summary>

+ [pid.cpp](./src/pid.cpp)
    + Initialize the constructor params as per [this](./docs/images/activity_diagram_PIDObjectCreation.png), - done
    + Implement the getters and setters, - done
    + Implement the `compute(double, double)` method as per the [activity diagram](./docs/images/activity_diagram_PID_compute_method.png). - done
+ Look for `TODO(Pair2)` in the workspace and implement the required methods.

</details>

-----


## Standard install via command-line
```
git clone --recursive https://github.com/anubhavparas/pid-controller-software.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```
or run: 
```
sh build_coverage_off.sh
```

## Building for code coverage
Install code-coverage tool, else the code coverage command will not work. It is a one time installation: 
```
sudo apt-get install lcov
```
```
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```

or run: 
```
sh build_coverage_on.sh
```

This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Run cppcheck and cpplint
Run cppcheck: Results are stored in `./results/cppcheck_process.txt`, `./results/cppcheck_result.txt` 
```
sh run_cppcheck.sh
```

Run cpplint: Results are stored in `./results/cpplint_result.txt`
```
sh run_cpplint.sh
```


## Working with Eclipse IDE ##

### Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/anubhavparas/pid-controller-software
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of pid-controller-software

```
cd ~/workspace
mkdir -p pid-eclipse
cd pid-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../pid-controller-software/
```

### Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "pid-eclipse" directory created previously as root directory -> Finish

### Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


### Build

To build the project, in Eclipse, unfold pid-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

### Run

1. In Eclipse, right click on the pid-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


