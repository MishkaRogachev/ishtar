# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(core)

# Library output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/result)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Gui REQUIRED)

# Includes
include_directories(
    sources/situation
)

# Sources
set(SOURCES
    sources/situation/geometry.cpp
    sources/situation/bounding_box.cpp
    sources/situation/node.cpp
    sources/situation/node_serializer/i_node_serializer.cpp
    sources/situation/node_serializer/json_node_serializer.cpp
    sources/situation/node_serializer/parsers/json_geometry_parser.cpp
)

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Static Library target
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Link Libraries
set (LIBRARIES Qt5::Core Qt5::Gui)
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})
