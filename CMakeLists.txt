#####################################
# Project
#####################################
cmake_minimum_required(VERSION 3.28)
project("Smart ECU"
    VERSION 1.0
    DESCRIPTION "Smart-Envrionmental-control-and-Safety-Gateway-ECU"
    LANGUAGES C CXX)
set(TARGET_NAME "Smart_ECU")
# Set C and C++ Standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#####################################
# Packages
#####################################

#####################################
# Sources (src)
#####################################
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/state_machine.cpp)
# if multiple sources set it under one variable
# Setting source as lib as it shall not be executed,
# but rather only as includes for test cases
add_executable(${TARGET_NAME} ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

#####################################
# Includes
#####################################
target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

#####################################
# Libraries
#####################################

#####################################
# Target properties
#####################################
add_definitions("-DBOOST_ALLOW_DEPRECATED_HEADERS")
target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wpedantic)
set_target_properties(${TARGET_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#####################################
# Test
#####################################
enable_testing()
# Test sources declaration
set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/unity.c
                ${CMAKE_CURRENT_SOURCE_DIR}/src/state_machine.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/main_test_runner.c)
# Setting test target
set(TEST_TARGET "tests")
# executable
add_executable(${TEST_TARGET} ${SOURCES} ${TEST_SOURCES})
# test includes
target_include_directories(${TEST_TARGET}
                        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
# compiler options
target_compile_options(${TEST_TARGET} PRIVATE -Wall -Wpedantic)
set_target_properties(${TEST_TARGET}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
