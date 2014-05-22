# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(app)

# Executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../result)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Quick 3DQuick REQUIRED)

# Includes
include_directories(
    sources
    ../core/sources/situation
    ../core/sources/classification
    ../presentation/sources/views/situation_node_view
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

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${QRC_SOURCES})

# Link Libraries
set (LIBRARIES core presentation Qt5::Core Qt5::Quick Qt5::3DQuick)
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})
