# Introduction

This project is a parser for s-expressions in C/C++. It was done by Nathanaël Beaudoin-Dion in the holiday period of 2019-2020 for the company GHGSat. This parser can be compiled and executed with CMake on any platform. Also, it supports cross-compilation with CMake. 

This README explains how to use and execute the SEXP-Parser on Windows and on Linux. After, it will go through the methodology on how the project was made and developed, to finish with improvements that could be made for the parser, what I learned throughout the process and difficulties encountered.

# How to use the parser

- The examples folder contains .sexp files the project can parse, where the parsed files can be chosen by the user when the project is executed
- The characters of value of 40 ("("), 41 (")") and from 44 (",") to 122 ("z") in the ASCII table are accepted and parsed
- The s-expression needs to have the same structure as the capture.sexp file, like so:
```c++
Capture {
    string header;
    string id;
    string name;
    string timestamp;
    Settings {
        string mode;
        unsigned int frequency;
        unsigned int fps;
        unsigned int exposure;
        float gain_r;
        float gain_g;
        float gain_b;
    };
    Coordinates {
        float latitude;
        float longitude;
        float altitude;
    };
};
```
- The parsed s-expressions contains "type:" and "value:" to clearly indicate the data-type and value elements
- The src folder contains the source code

## Running the project

The SEXP-Parser can be compiled and executed with CMake on Windows and Linux with an IDE (CLion) or with CMake-GUI.

### CLion

This project was made using the CLion IDE by JetBrains (https://www.jetbrains.com/). The project can be compiled, executed and debugged with this IDE using the CMakeList file in the repository and any toolchain compatible with the machine running the project. 

#### Windows

To download CLion on Windows, go on the official website of JetBains. For the toolchain, I recommend to use MinGW with CLion on Windows. See this tutorial on how to setup CLion with MinGW on Windows: https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html. 

Here is the settings for the toolchain on Windows:
![Toolchain-Windows](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/clion/toolchain-setting-windows.PNG)

#### Linux

CLion can be downloaded on Linux via command line (see https://www.jetbrains.com/help/clion/installation-guide.html), via internet on the official website of JetBains or via a software installer on Ubuntu. For Linux, I recommend to use the default toolchain.

Here is the settings for the toolchain on Linux Ubuntu:
![Toolchain-Linux](https://github.com/Spaceless007/SEXP-Parser/blob/master/resources/clion/toolchain-setting-linux.png)

### CMake-GUI

The next subsections explains how to compile and cross-compile with the graphical tool of CMake. Either on Windows or Linux, it needs the same application and works the same way. From Windows, CMake-GUI is downloaded when CMake is downloaded. For Linux on Ubuntu, the software installer user interface can be used.

#### Compilation

To run the SEXP-Parser with CMake-GUI, first CMake needs to be installed: https://cmake.org/download/. Afterward, the project can be executed with the help of CMake-GUI provided by CMake when it is installed.

First, complete the two upper dialog boxes (NOTE: for the build directory, it is recommended to create a new one named ```build```): 
![CMake-GUI](https://github.com/Spaceless007/SEXP-Parser/blob/master/resources/cmake/cmake-gui-windows-1.PNG)

After, click on the button ```Configure```, choose the ```MinGW Makefiles``` and the ```Use default native compilers``` option:
![CMake-GUI](https://github.com/Spaceless007/SEXP-Parser/blob/master/resources/cmake/cmake-gui-windows-2.PNG)

Then, click on ```Generate```. Now, the build folder should contain a generated Makefile. To build and generate the executable file SEXP-Parser.exe, type in the command ```make``` inside a command prompt at the Makefile location, which is ```SEXP-Parser/build```. To execute the source code, simply execute the ```SEXP-Parser.exe``` file. 

#### Cross-Compilation

Like it is showed for the compilation on the subsection above, complete the two upper dialog boxes. Then, click on the ```Configure``` button and choose also the MinGW Makefiles. But, instead, choose the ```Specify options for cross-compiling```. With this tool, CMake can cross-compile with any compilers.

Here is an example of Windows hosted cross-compilation to a Linux AArch64 GNU/Linux target (aarch64-none-linux-gnu):
![CMake-GUI-CrossCompilation](https://github.com/Spaceless007/SEXP-Parser/blob/master/resources/cmake/cmake-gui-crosscompile.PNG)

After, it is the same procedure as the compilation showed above: click on ```Generate```, execute the command ```make``` in a command prompt and execute the ```SEXP-Parser``` file.

Link to various toolchains for cross-compiling that can be used with the CMake-GUI:
- Build for Linux ARM based from various sources: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
- Build for Raspberry Pi from Linux: https://github.com/raspberrypi/tools/tree/master/arm-bcm2708
  - For Pi 1, Zero, Zero W use the ```bcmrpi```
  - For Pi 2, 3, 3+ use the ```bcm2709```
  - For Pi 4 use the ```bcm2711```
  - To cross-compile using only command lines without the CMake-GUI and more, see the section on cross-compiling of the official documentation of Raspberry Pi: https://www.raspberrypi.org/documentation/linux/kernel/building.md
- Build for BeagleBoard from Linux: https://github.com/beagleboard/linux
  - Follow the instructions in the section on cross-compiling https://www.itdev.co.uk/blog/building-linux-kernel-cross-compiling-beaglebone-black

# Methodology

The next subsections explains the process to develop the parser, starting by research and architecture, then completing the implementation and documentation of the source code.

## 1. Research

Symbolic expressions are represented by binary trees. Because of this, I thought about implementing a tree for this parser. Thing is, the more I thought about it, the more it seemed overkill. Trees are useful when we want to search en element,to reorganise the tree, to remove certain elements, and many other features. Since this project doesn't use these features, it was not considered necessary to implement a tree for the parser.

## 2. Architecture and implementation

Considering the parser is not implemented with binary trees, there isn't a need to have an oriented-object source code since the SEXP-Parser only needed three main functionality: read .sexp files, parse the files and print the resulting s-expression. Hence, the project is a procedural C++ program with one main file, one other .cpp file (with it's corresponding .hpp file) containing the necessary functions and one CMakeList to build the project with CMake.

The parser is implemented using strings to take advantage of their functions to parse the files. Since it is using strings, `iostream` seemed to be simpler to use. Even though compared to `cstdio` it is slower and takes more memory, it is not considered a problem since it is a simple and small program.

## 3. Documentation

The documentation for the source files of the project is following the Doxygen standard. It takes advantages of the decorators (example: @param) to make it visually pleasing. Also, these decorators are supported in the CLion IDE, which can be really useful since it is easier to see the description of the function, the parameters, the return value and much more. 

# How to improve the project

- It takes a lot of steps to cross-compile with CMake-GUI, which is why bash scripts for each useful cases could be implemented to accelerate the cross compilation process.
- The parser doesn't implement the use of "", where it could be used to add elements with spaces inside their values
- The print of s-expressions is not pretty, it could be prettier (for example, print it like a tree)
- Support special characters like "é" with the UTF-8 encoding

# What I learned and difficulties encountered

- This project was the first coding project I made from start to finish alone, setting up CMake, CLion, etc. Generally, I am aware of everything about a project from a high level, and I participate in details on certain aspects. But I rarely go through the hole process and every line of codes in details alone. Thereby, I learned on aspects I didn't go through in details on past projects, for example, how to compile the project with CMake or Makefile.
- Learned a lot on everything about CMake and compilation in general. I had a vague idea how the compilation worked in the past, but now I understand it more clearly. 
- Since I didn't understand well enough CMake, the compilation process, the importance of toolchains, it took me a while to find the resources and to understand how to cross-compile.
- I did not test the cross-compile builds for Raspberry Pi, Beagleboard and ARM qemu emulator since I didn't have a Pi or BB, and had limited access to a Linux computer.
- I did not understand how to cross-compile for ARM qemu emulator.
