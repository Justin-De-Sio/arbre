cmake_minimum_required(VERSION 3.20)
project(arbre)

set(CMAKE_CXX_STANDARD 14)

add_executable(arbre main.cpp crdtree.hpp node.hpp)
