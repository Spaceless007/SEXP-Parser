# Introduction

This project is a parser for s-expressions in C/C++. It was done by Nathanaël Beaudoin-Dion in the holiday period of 2019 for the company GHGSat. [Enter here features, cross-plateform, etc.]

# How to use the parser

## Running the project

### CLion

This project was made using the CLion IDE by JetBrains. The project can be compiled, executed and debugged with this IDE using the CMakeList file and any toolchain compatible with the machine running the project. Since this project was made using Windows 10, the toolchain used was MinGW.

### Windows

To run the SEXP-Parser on Windows with CMake, first CMake needs to be installed: https://cmake.org/download/. Afterward, the project can be executed with the CMake-GUI provided by CMake when it is installed.

First, complete the two upper dialog boxes (NOTE: for the build directory, it is recommanded to create a new one named ```build```): 

![CMake-GUI](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-windows-1.PNG)

After, click on the button ```Configure``` and choose the MinGW Makefiles:

![CMake-GUI](https://github.com/Spaceless007/SEXP-Parser/blob/master/ressources/cmake/cmake-gui-windows-2.PNG)

Then, click on ```Generate```. Now, the build folder should contain a generated Makefile. To build and generate the executable file SEXP-Parser.exe, type in the command ```make``` inside a command prompt at the Makefile location, which is ```SEXP-Parser/build```. To execute the source code, simply execute the ```SEXP-Parser.exe``` file. 

### Linux

### Raspberry Pi

# Methodology

Since this was a small project, the research and the architecture for this project wasn't long to make *((CHANGER CETTE PHRASE))*. The next subsections explains the process to execute the task explained in the CHALLENGE.md document, starting by research and architecture, then completing the implmentation and documentation of the source code for the parser, to finally include the ability to run the parser on multiple platfroms. 

## 1. Research

To start with, research on symbolic expressions explains they were popularized by the programming language Lisp. They are represented by binary trees. Since they are represented by trees, I thought about implementing a tree for this parser. Thing is, the more I thought about it, the more it seemed overkill. Trees are usefull when we want to search en element, when we want to reorganise the tree, to remove certain elements, and many other features. Since this project doesn't use these features, it is not necessary to implement a tree for the parser. 

## 2. Architecture

Considering the parser was not going to be implemented with binary trees, there wasn't a need to go for an oriented-object source code since the SEXP-Parser only needed three functionnality: read .sexp files, parse the files and print the resulting s-expression. With this in mind, *((CHANGER LE THAT IN MIND))* the project is a procedural C++ program with one main file, one other .cpp file (with it's corresponding header file) and one makefile and CMakeList to build the project. 

## 3. Implementation

## 4. Documentation

The documentation for the source files of the project is following the Doxygen standard. It takes avantages of the decorators (example : @param) to make it visually pleasing. Also, these decorators are supported in the CLion IDE, which can be really usefull when a project starts to get bigger, since it is easier to see the description of the function, the parameters and the return value. 

## 5. Cross-platforming

# Conclusion and How to improve the parser

[Conclude, talk about the project, what I learned, the difficulties, etc.] 
