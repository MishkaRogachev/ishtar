# Cmake version string
cmake_minimum_required(VERSION 2.8.9)

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
find_package(Qt5Network REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir,
# tell CMake to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Static Library target
add_library(${PROJECT_NAME} STATIC ${SOURCES})
