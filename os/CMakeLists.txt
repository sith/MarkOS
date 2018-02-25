cmake_minimum_required(VERSION 3.9)
project(os)


add_library(${PROJECT_NAME}
        src/cycle/Cycle.h
        src/cycle/Cycle.cpp
        src/cycle/CycleListener.h
        src/Random.h
        src/controller/Controller.h
        src/controller/Controller.cpp
        src/environment/Environment.h
        src/environment/Environment.cpp
        src/logger/Logger.h
        src/logger/LoggerFactory.h
        src/modes/Mode.h
        src/modes/Mode.cpp
        src/modes/EmptyModeListener.h
        src/modes/EmptyModeListener.cpp
        src/modes/ModeListener.h
        src/modes/ModeName.h
        src/modes/ModeManager.h
        src/modes/ModeManager.cpp
        src/modes/test/TestMode.h
        src/modes/test/TestMode.cpp
        src/state/State.h
        src/state/standard/NoopState.h
        src/state/standard/NoopState.cpp
        src/state/DirectTransition.h
        src/state/DirectTransition.cpp
        src/time/Clock.h
        src/time/Timer.h
        src/time/Timer.cpp
        src/time/TimerTask.h
        src/time/TimerTask.h
        src/time/TimerTask.cpp
        src/time/TimerListener.h
        src/state/standard/PrintState.cpp
        src/state/standard/PrintState.h
        src/state/standard/WaitState.cpp
        src/state/standard/WaitState.h
        src/controller/Command.h
        src/controller/ControllerCommandListener.h
        src/logger/LoggerFactory.cpp
        src/modes/supervised/SupervisedMode.cpp
        src/modes/supervised/SupervisedMode.h
        src/drivers/MotorDriver.h
        src/sensors/ObstacleSensor.h
        src/sensors/ObstacleSensor.cpp
        src/modes/freerun/FreeRunMode.cpp
        src/modes/freerun/FreeRunMode.h
        src/state/standard/ConditionalState.cpp
        src/state/standard/ConditionalState.h
        src/state/State.cpp
        src/missioncontrol/Mission.cpp
        src/missioncontrol/Mission.h
        src/missioncontrol/MissionManager.h src/missioncontrol/MissionManager.cpp src/memory/MemoryMonitor.h)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)
target_include_directories(${PROJECT_NAME} PUBLIC src)
add_subdirectory(test)

install(DIRECTORY "src/"
        DESTINATION "/Users/oleksandrabaukh/workspace/myLibs/MarkOS_os")