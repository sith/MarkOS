cmake_minimum_required(VERSION 3.9)
project(MarkOS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")


add_subdirectory(common)
add_subdirectory(common_tests)
add_subdirectory(os)

