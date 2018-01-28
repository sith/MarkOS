
add_executable(os_tests
        main.cpp
        cycle/CycleTest.cpp
        cycle/CycleTest.h
        cycle/MockCycleListener.h
        modes/test/TestModeTest.cpp
        modes/test/TestModeTest.h
        statemachine/StateMachineTest.cpp
        statemachine/StateMachineTest.h
        time/TimerTest.cpp
        time/TimerTest.h
        time/MockClock.h
        time/MockTimerListener.h
        modes/ModeManagerTest.h
        modes/ModeManagerTest.cpp
        emulator/logger/StdOutLogger.cpp emulator/logger/StdOutLogger.h emulator/logger/StdOutLoggerFactory.cpp emulator/logger/StdOutLoggerFactory.h)
#Link with GoogleTest
target_link_libraries(os_tests os)
target_link_libraries(os_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(os_tests gmock gmock_main)
