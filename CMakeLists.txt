cmake_minimum_required(VERSION 3.14)
project(SEXP_Parser)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(examples)
include_directories(src)

add_executable(SEXP_Parser
        src/main.cpp
        src/sexp-parser.cpp
        src/sexp-parser.hpp)
