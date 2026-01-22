if (BUILD_TESTING)
    add_executable(exeTest test.cpp)
    target_link_libraries(exeTest PRIVATE 
            gtest_main
            SZKM
            )

    include(GoogleTest)
    gtest_discover_tests(exeTest)

    add_executable(zad2Test test_z2.cpp)
    
    target_link_libraries(zad2Test PRIVATE 
            gtest_main
            gmock_main 
            SZKM
            )

    include(GoogleTest)
    gtest_discover_tests(zad2Test)
endif()