
add_executable(os_tests
        main.cpp
        cycle/CycleTest.cpp
        cycle/CycleTest.h
        cycle/MockCycleListener.h
        time/TimerTest.cpp
        time/TimerTest.h
        mocks/MockClock.h
        mocks/MockFileSystem.h
        time/MockTimerListener.h
        modes/ModeManagerTest.h
        modes/ModeManagerTest.cpp
        controller/ControllerTest.cpp
        controller/ControllerTest.h
        controller/TestController.cpp
        controller/TestController.h
        mocks/MockModeListener.h
        mocks/MockControllerCommandListener.h
        mocks/MockController.h
        mocks/MockRandom.h
        modes/supervised/SupervisedModeTest.cpp
        modes/supervised/SupervisedModeTest.h
        mocks/MockMotorDriver.h mocks/MockObstacleSensor.h
        mocks/MockEnvironment.h
        mocks/MockFile.h
        mocks/MockMissionIdGenerator.h
        )

target_link_libraries(os_tests emulator_lib)

#Link with GoogleTest
target_link_libraries(os_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(os_tests gmock gmock_main)
