
add_executable(commons_tests
        main.cpp
        collections/LinkedListTest.h
        collections/LinkedListTest.cpp
        )

#Link with GoogleTest
target_link_libraries(commons_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(commons_tests gmock gmock_main)
target_link_libraries(commons_tests common)