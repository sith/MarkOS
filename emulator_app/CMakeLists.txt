cmake_minimum_required(VERSION 3.9)
project(emulator_app)

add_executable(${PROJECT_NAME}
        src/Emulator.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC os)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC emulator_lib)
