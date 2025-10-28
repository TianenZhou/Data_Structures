cmake_minimum_required(VERSION 3.10)
project(LinkedListProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCE_FILES src/Special_functions_of_data_structures/Check_If_A_Given_Binary_Tree_Is_BST.cpp)

add_executable(main ${SOURCE_FILES})