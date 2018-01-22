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
        src/state/State.h
        src/state/NoopState.h
        src/state/NoopState.cpp
        src/state/DirectTransition.h
        src/state/DirectTransition.cpp
        src/time/Clock.h
        src/time/Timer.h
        src/time/Timer.cpp
        src/time/TimerTask.h
        src/time/TimerTask.h
        src/time/TimerTask.cpp
        src/time/TimerListener.h



        )
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC common)
add_subdirectory(test)