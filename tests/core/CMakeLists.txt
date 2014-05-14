# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(core_tests)

# Test executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/result/tests)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Test REQUIRED)

# Includes
include_directories(
    ../../core/sources/situation
    unit_tests/situation/
)

# Test Sources
set(TEST_SOURCES
    core_tests.cpp
    unit_tests/situation/node_test.cpp
)

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Link Libraries
set (LIBRARIES core Qt5::Core Qt5::Test)
target_link_libraries (${PROJECT_NAME} ${LIBRARIES} ${QT_QTTEST_LIBRARY})

# Tests
add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
