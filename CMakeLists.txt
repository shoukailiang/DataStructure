cmake_minimum_required(VERSION 3.14)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure Graph/Weighted-Graph/Edge.h Graph/Weighted-Graph/DenseGraph.h Graph/Weighted-Graph/SparseGraph.h Graph/Weighted-Graph/ReadGraph.h Graph/Weighted-Graph/main.cpp)