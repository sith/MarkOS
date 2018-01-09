cmake_minimum_required(VERSION 3.9)
project(common)


add_library(${PROJECT_NAME}
        src/List.h
        src/LinkedList.cpp
        src/LinkedList.h src/Queue.h)
target_include_directories(${PROJECT_NAME} PUBLIC src)
