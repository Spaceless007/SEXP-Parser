# Introduction

This project is a parser for s-expressions in C/C++. It was done by Nathanaël Beaudoin-Dion in the holiday period of 2019-2020 for the company GHGSat. This parser can be compiled and executed with CMake on any platform. Also, it supports cross-compilation with CMake. 

This README explains how to use and execute the SEXP-Parser on Windows and on Linux. After, it will go through the methodology on how the project was made and developped, to finish with improvements that could be made for the parser, what I learned throughout the process and difficulties encountered.

# How to use the parser

- The examples folder contains .sexp files the project can parse, where the parsed files can be choosed by the user when the project is executed
- The characters from value 40 ("("), 41 (")"), 44 (",") to 122 ("z") in the ASCII table are accepted and parsed
- The parsed s-expressions contains "d:" and "v:" to clearly indicate the data-type and value element
- The src folder contains the source code

## Running the project

The SEXP-Parser can be compiled and executed with CMake on Windows, Linux with or without an IDE. For Windows or Linux, a toolchain needs to be downloaded to compile the project (for Windows, MinGW was used during development of the parser). 

### CLion

This project was made using the CLion IDE by JetBrains (https://www.jetbrains.com/). The project can be compiled, executed and debugged with this IDE using the CMakeList file in the repository and any toolchain compatible with the machine running the project. 

#### Windows

To download CLion on Windows, go on the official website of JetBains. For the toolchain, I recommend to use MinGW with CLion on Windows. See this tutorial on how to setup CLion with MinGW on Windows: https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html. 

Here is the settings for the toolchain on Windows:
![Toolchain-Windows](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/clion/toolchain-setting-windows.PNG)

#### Linux

CLion can be downloaded on Linux via command line (see https://www.jetbrains.com/help/clion/installation-guide.html), via internet on the official website of JetBains or via a software installer on Ubuntu. For the toolchain, I recommand to use the default.

Here is the settings for the toolchain on Linux Ubuntu:
![Toolchain-Linux](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/clion/toolchain-setting-linux.png)

### CMake-GUI

The next subsections explains how to compile and cross-compile with the graphical tool of CMake. Either on Windows or Linux, it needs the same application and works the same way. From Windows, CMake-GUI is downloaded when CMake is downloaded. For Linux on Ubuntu, the software installer user interface can be used.

#### Compilation

To run the SEXP-Parser with CMake-GUI, first CMake needs to be installed: https://cmake.org/download/. Afterward, the project can be executed with the help of CMake-GUI provided by CMake when it is installed.

First, complete the two upper dialog boxes (NOTE: for the build directory, it is recommanded to create a new one named ```build```): 
![CMake-GUI](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-windows-1.PNG)

After, click on the button ```Configure```, choose the ```MinGW Makefiles``` and the ```Use default native compilers``` option:
![CMake-GUI](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-windows-2.PNG)

Then, click on ```Generate```. Now, the build folder should contain a generated Makefile. To build and generate the executable file SEXP-Parser.exe, type in the command ```make``` inside a command prompt at the Makefile location, which is ```SEXP-Parser/build```. To execute the source code, simply execute the ```SEXP-Parser.exe``` file. 

#### Cross-Compilation

Like it is showned for the compilation on the subsection above, complete the two upper dialog boxes. Then, click on the ```Configure``` button and choose also the MinGW Makefiles. But, instead, choose the ```Specify options for cross-compiling```. With this tool, CMake can cross-compile with any compilers.

Here is an example of Windows hosted cross-compilation to a Linux AArch64 GNU/Linux target (aarch64-none-linux-gnu):
![CMake-GUI-CrossCompilation](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-crosscompile.PNG)

After, it is the same procedure as the compilation showned above: click on ```Generate```, execute the command ```make``` in a command prompt and execute the ```SEXP-Parser``` file.

Link to various toolchains for cross-compiling that can be used with the CMake-GUI:
- Build for Linux ARM based from various sources: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
- Build for Raspberry Pi from Linux: https://github.com/raspberrypi/tools/tree/master/arm-bcm2708
  - For Pi 1, Zero, Zero W use the ```bcmrpi```
  - For Pi 2, 3, 3+ use the ```bcm2709```
  - For Pi 4 use the ```bcm2711```
  - To cross-compile using only command lines without the CMake-GUI and more, see the section on cross-compiling of the official documentation of Raspberry Pi: https://www.raspberrypi.org/documentation/linux/kernel/building.md

# Methodology

The next subsections explains the process to develop the parser, starting by research and architecture, then completing the implmentation and documentation of the source code.

## 1. Research

Symbolic expressions are represented by binary trees. Because of this, I thought about implementing a tree for this parser. Thing is, the more I thought about it, the more it seemed overkill. Trees are usefull when we want to search en element,to reorganise the tree, to remove certain elements, and many other features. Since this project doesn't use these features, it was not considered necessary to implement a tree for the parser.

## 2. Architecture and implementation

Considering the parser is not implemented with binary trees, there isn't a need to have an oriented-object source code since the SEXP-Parser only needed three main functionnalities: read .sexp files, parse the files and print the resulting s-expression. Hence, the project is a procedural C++ program with one main file, one other .cpp file (with it's corresponding .hpp file) containing the necessary functions and one CMakeList to build the project with CMake.

## 3. Documentation

The documentation for the source files of the project is following the Doxygen standard. It takes avantages of the decorators (example : @param) to make it visually pleasing. Also, these decorators are supported in the CLion IDE, which can be really usefull since it is easier to see the description of the function, the parameters, the return value and much more. 

# How to improve the parser

This project can be improved in many ways:
- Faire script python pour compilation et cross-compilation de CMake sans IDE
- Implementer le support de "" dans les expressions pour ajouter des espaces
- Avoir un print plus beau

# What I learned and difficulties encountered
- Apprendre à faire une application de A à Z par soi-même, premier projet de code individuel
- Apprendre CMake, compilateurs, cross-compilers, toolchains
- Difficultés avec ce dernier point, surtout cross-compiling
