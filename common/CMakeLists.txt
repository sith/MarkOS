cmake_minimum_required(VERSION 3.9)
project(common)

add_library(${PROJECT_NAME}
        src/List.h
        src/LinkedList.h
        src/LinkedList.h src/some.cpp src/Iterator.h)
target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(test)