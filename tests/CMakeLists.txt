if (BUILD_TESTING)
    add_executable(exeTest test.cpp)
    target_link_libraries(exeTest PRIVATE 
            GTest::gtest_main
            SZKM
            )

    include(GoogleTest)
    gtest_discover_tests(exeTest)
endif()