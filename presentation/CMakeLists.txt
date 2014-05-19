# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(presentation)

# Library output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/result)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Gui 3DQuick REQUIRED)

# Includes
include_directories(
    ../common
    ../core/sources/situation
    sources/
)

# Sources
set(SOURCES
    sources/view_items/situation_node_view_item.cpp
)

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Static Library target
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Link Libraries
set (LIBRARIES core Qt5::Core Qt5::Gui Qt5::3DQuick)
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})
