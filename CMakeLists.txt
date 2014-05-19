# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(ishtar)

# Testing
enable_testing()

# Subprojects
add_subdirectory(core)
add_subdirectory(presentation)
add_subdirectory(app)

# Tests
add_subdirectory(tests/core)
