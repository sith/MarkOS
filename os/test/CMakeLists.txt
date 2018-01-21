
add_executable(os_tests
        main.cpp
        )
#Link with GoogleTest
target_link_libraries(os_tests os)
target_link_libraries(os_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(os_tests gmock gmock_main)
