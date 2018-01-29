cmake_minimum_required(VERSION 3.9)
project(emulator_lib)

add_library(${PROJECT_NAME}
        src/logger/StdOutLogger.h
        src/logger/StdOutLogger.cpp
        src/logger/StdOutLoggerFactory.h
        src/logger/StdOutLoggerFactory.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC os)