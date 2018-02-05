cmake_minimum_required(VERSION 3.9)
project(emulator_lib)

add_library(${PROJECT_NAME}
        src/logger/StdOutLogger.h
        src/logger/StdOutLogger.cpp
        src/logger/StdOutLoggerFactory.h
        src/logger/StdOutLoggerFactory.cpp
        src/clock/SystemClock.cpp
        src/clock/SystemClock.h
        src/RemoteCommand.h
        src/controller/EmulatorController.cpp src/controller/EmulatorController.h RemoteCommand.cpp src/drivers/EmulatorMotorDriver.cpp src/drivers/EmulatorMotorDriver.h src/sensors/EmulatorObstacleSensor.cpp src/sensors/EmulatorObstacleSensor.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC os)