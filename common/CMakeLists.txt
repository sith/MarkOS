cmake_minimum_required(VERSION 3.9)
project(common)

add_library(${PROJECT_NAME}
        src/collections/List.h
        src/collections/LinkedList.h
        src/collections/LinkedList.h
        src/some.cpp
        src/collections/Iterator.h
        src/memory/Pointer.cpp
        src/memory/Pointer.h
        src/filesystem/File.h
        src/filesystem/FileSystem.h
        src/string/String.cpp src/string/String.h src/memory/move.h)
target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(test)

install(DIRECTORY "src/"
        DESTINATION "/Users/oleksandrabaukh/workspace/myLibs/MarkOS_common")