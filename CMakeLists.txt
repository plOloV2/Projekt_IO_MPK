cmake_minimum_required(VERSION 3.28)
project(SystemZarzadzaniaKomunikacjaMiejska VERSION 0.0.1
                    DESCRIPTION "Try googletest"
                    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pipe")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -DDEBUG_MSG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -march=native -flto -fomit-frame-pointer")

include(cmake/UpdateSubmodule.cmake)

include(CTest)

add_subdirectory(googletest)
add_subdirectory(tests)

file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(SZKM STATIC ${PROJECT_SOURCES})

target_include_directories(SZKM PUBLIC
    ${CMAKE_SOURCE_DIR}/inc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/inc")

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_link_libraries(${PROJECT_NAME} PRIVATE SZKM)

