# CMake version string
cmake_minimum_required(VERSION 2.8.9)

# Project
set(PROJECT app)
project(${PROJECT})

# Includes
include_directories(
    sources
)

# Sources
set(SOURCES
    sources/main.cpp
)

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Executable
add_executable(PROJECT ${SOURCES})

# Libraries
set (LIBRARIES core ${QT_LIBRARIES} Qt5::Core Qt5::Quick)
target_link_libraries (PROJECT ${LIBRARIES})
