# Cmake version string
cmake_minimum_required(VERSION 2.8.9)

# Project
set(PROJECT ishtar)
project(${PROJECT})

# Subdirs
add_subdirectory(core)
# add_subdirectory(ui)
add_subdirectory(app)
