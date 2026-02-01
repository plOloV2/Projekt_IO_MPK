if (BUILD_TESTING)
    add_executable(TestDAO model/TestDAO.cpp)
    target_link_libraries(TestDAO PRIVATE 
            GTest::gtest_main
            SZKM
            )

    include(GoogleTest)
    gtest_discover_tests(TestDAO)

    add_executable(zad2Test kontroler/TestModyfikowanieRozkladuJazdy.cpp)
    
    target_link_libraries(zad2Test PRIVATE 
            gtest_main
            gmock_main 
            SZKM
            )

    include(GoogleTest)
    gtest_discover_tests(zad2Test)

    file(GLOB KONTROLER_FILES "kontroler/*.cpp")

    add_executable(TestKontroler ${KONTROLER_FILES})

    target_link_libraries(TestKontroler PRIVATE
            gtest_main
            gmock_main 
            SZKM
            )

    add_test(NAME SuiteTestyKontrolera COMMAND TestKontroler)

    file(GLOB MODEL_FILES "model/*.cpp")

    add_executable(TestModel ${MODEL_FILES})

    target_link_libraries(TestModel PRIVATE
            GTest::gtest_main
            SZKM
            )

    add_test(NAME SuiteTestyModelu COMMAND TestModel)

    add_executable(TestyAll ${KONTROLER_FILES} ${MODEL_FILES})

    target_link_libraries(TestyAll PRIVATE
            gtest_main
            gmock_main 
            SZKM
            )

    add_test(NAME SuiteTestyEdycji
            COMMAND TestyAll --gtest_filter=*Edycja*)

    add_test(NAME SuiteTestyZnalezienia
            COMMAND TestyAll --gtest_filter=*Znalezienie*)
endif()
