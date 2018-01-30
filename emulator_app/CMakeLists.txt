cmake_minimum_required(VERSION 3.9)
project(emulator_app)

find_package(Boost 1.66 REQUIRED COMPONENTS
        filesystem iostreams)
include_directories(${Boost_INCLUDE_DIRS})


add_executable(${PROJECT_NAME}
        src/Emulator.cpp src/client/Command.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC os)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC emulator_lib)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})


add_executable(${PROJECT_NAME}_client
        src/client/EmulatorClient.cpp)

target_include_directories(${PROJECT_NAME}_client PUBLIC src)
target_link_libraries(${PROJECT_NAME}_client LINK_PUBLIC common)
target_link_libraries(${PROJECT_NAME}_client LINK_PUBLIC os)
target_link_libraries(${PROJECT_NAME}_client LINK_PUBLIC emulator_lib)
target_link_libraries(${PROJECT_NAME}_client LINK_PUBLIC ${Boost_LIBRARIES})
