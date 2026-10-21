cmake_minimum_required(VERSION 3.21)
project(FrameAssist VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please set GEODE_SDK environment variable.")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Aquí es donde Geode detecta automáticamente el mod y sus fuentes sin romper Android
setup_geode_mod(${PROJECT_NAME})
