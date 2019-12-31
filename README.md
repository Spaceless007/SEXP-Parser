# Introduction

This project is a parser for s-expressions in C/C++. It was done by Nathanaël Beaudoin-Dion in the holiday period of 2019-2020 for the company GHGSat. This parser can be compiled and executed with CMake on any platform. Also, it supports cross-compilation with CMake. 

This README explains how to use and execute the SEXP-Parser on Windows and on Linux. After, it will go through the methodology on how the project was made and developped, to finish with improvements that could be made for the parser, what I learned throughout the process and difficulties encountered.

# How to use the parser

- The examples folder contains .sexp files the project can parse
- The src folder contains the source code
- THE BUILD FOLDER ?

## Running the project

The SEXP-Parser can be compiled and executed with CMake on Windows, Linux with or without an IDE.

### CLion

This project was made using the CLion IDE by JetBrains (https://www.jetbrains.com/). The project can be compiled, executed and debugged with this IDE using the CMakeList file in the repository and any toolchain compatible with the machine running the project. Since this project was made using Windows 10, the toolchain used was MinGW. See this tutorial on how to setup CLion with MinGW on Window: https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html. 

### Windows

The next subsections explain how to compile and cross-compile with Windows.

#### Compilation

To run the SEXP-Parser on Windows with CMake, first CMake needs to be installed: https://cmake.org/download/. Afterward, the project can be executed with the help of CMake-GUI provided by CMake when it is installed.

First, complete the two upper dialog boxes (NOTE: for the build directory, it is recommanded to create a new one named ```build```): 
![CMake-GUI-Windows](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-windows-1.PNG)

After, click on the button ```Configure```, choose the ```MinGW Makefiles``` and the ```Use default native compilers``` option:
![CMake-GUI-Windows](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-windows-2.PNG)

Then, click on ```Generate```. Now, the build folder should contain a generated Makefile. To build and generate the executable file SEXP-Parser.exe, type in the command ```make``` inside a command prompt at the Makefile location, which is ```SEXP-Parser/build```. To execute the source code, simply execute the ```SEXP-Parser.exe``` file. 

#### Cross-Compilation

To cross-compile with Windows, the CMake-GUI is also needed.

Like it is showned for the compilation on Windows subsection above, complete the two upper dialog boxes. Then, click on the ```Configure``` button and choose also the MinGW Makefiles. But, instead, choose the ```Specify options for cross-compiling```. With this tool, CMake can cross-compile with any compilers. Linux ARM based toolchains can be downloaded here: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads. 

Here is an example how a cross-compilation from Windows to Linux AArch64 GNU/Linux target (aarch64-none-linux-gnu):
![CMake-GUI-CrossCompilation](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-crosscompile.PNG)

After, it is the same procedure as the compilation showned above: click on ```Generate```, execute the command ```make``` in a command prompt and execute the ```SEXP-Parser``` file.

### Linux

The next subsections explain how to compile and cross-compile with Linux.

# Methodology

Since this was a small project, the research and the architecture for this project wasn't long to make *((CHANGER CETTE PHRASE))*. The next subsections explains the process to execute the task explained in the CHALLENGE.md document, starting by research and architecture, then completing the implmentation and documentation of the source code for the parser, to finally include the ability to run the parser on multiple platfroms. 

## 1. Research

To start with, research on symbolic expressions explains they were popularized by the programming language Lisp. They are represented by binary trees. Since they are represented by trees, I thought about implementing a tree for this parser. Thing is, the more I thought about it, the more it seemed overkill. Trees are usefull when we want to search en element, when we want to reorganise the tree, to remove certain elements, and many other features. Since this project doesn't use these features, it is not necessary to implement a tree for the parser. 

## 2. Architecture and implementation

Considering the parser was not going to be implemented with binary trees, there wasn't a need to go for an oriented-object source code since the SEXP-Parser only needed three functionnality: read .sexp files, parse the files and print the resulting s-expression. Hence, the project is a procedural C++ program with one main file, one other .cpp file (with it's corresponding header file) containing the necessary functions and one CMakeList to build the project.

## 3. Documentation

The documentation for the source files of the project is following the Doxygen standard. It takes avantages of the decorators (example : @param) to make it visually pleasing. Also, these decorators are supported in the CLion IDE, which can be really usefull when a project starts to get bigger, since it is easier to see the description of the function, the parameters and the return value. 

## 4. How to improve the parser

This project can be improved in many ways:
- Faire script python pour compilation et cross-compilation de CMake sans IDE.
- Ajout parse the folder dans example

[Conclude, talk about the project, what I learned, the difficulties, etc.] 

# What I learned and difficulties encountered

