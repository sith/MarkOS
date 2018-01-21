cmake_minimum_required(VERSION 3.9)
project(MarkOS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

#Add the google test subdirectory
add_subdirectory(googletest-master)

#include googletest/include dir
include_directories(googletest-master/googletest/include)

#include the googlemock/include dir
include_directories(googletest-master/googlemock/include)

add_subdirectory(common)
add_subdirectory(os)

