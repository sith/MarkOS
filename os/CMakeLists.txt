cmake_minimum_required(VERSION 3.9)
project(os)


add_library(${PROJECT_NAME} src/OS.h src/OS.cpp)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)