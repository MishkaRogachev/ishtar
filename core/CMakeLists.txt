# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
set(PROJECT core)
project(${PROJECT})

# Includes
include_directories(
    sources/situation_map
)

# Sources
set(SOURCES
    sources/situation_map/situation_map.cpp
)

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Qt5 Packages
find_package(Qt5Core REQUIRED)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Static Library target
add_library(${PROJECT_NAME} STATIC ${SOURCES})
