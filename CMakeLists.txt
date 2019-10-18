cmake_minimum_required(VERSION 3.14)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure  UnionFind/UnionFind.cpp UnionFind/UnionFind.h ZJU_Programming_assignments/二分查找.cpp ZJU_Programming_assignments/两个有序链表序列的合并.cpp "ZJU_Programming_assignments/Maximum-Subsequence-Sum.cpp" ZJU_Programming_assignments/Reversing-Linked-List.cpp "ZJU_Programming_assignments/树的同构 (25 分).cpp" ZJU_Programming_assignments/是否同一颗二叉搜索树.cpp ZJU_Programming_assignments/堆中的路径.cpp)