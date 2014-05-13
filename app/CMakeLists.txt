# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
set(PROJECT app)
project(${PROJECT})

# Executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../result)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Includes
include_directories(
    sources
)

# Sources
set(SOURCES
    sources/main.cpp
)

# Resources
set(RESOURCES
    resources.qrc
)

# Compile resources to QRC_SOURCES and add it to include path
qt5_add_resources(QRC_SOURCES ${RESOURCES})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Executable
add_executable(PROJECT ${SOURCES} ${QRC_SOURCES})

# Link Libraries
set (LIBRARIES core Qt5::Core Qt5::Quick)
target_link_libraries (PROJECT ${LIBRARIES})
