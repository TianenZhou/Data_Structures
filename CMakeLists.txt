cmake_minimum_required(VERSION 3.10)
project(LinkedListProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCE_FILES src/Tree.cpp)

add_executable(main ${SOURCE_FILES})