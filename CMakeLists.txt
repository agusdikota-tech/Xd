cmake_minimum_required(VERSION 3.21)
project(FrameAssist VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please set GEODE_SDK environment variable.")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Declaramos la biblioteca vinculándola directamente al archivo principal de tu carpeta src
add_library(FrameAssist SHARED src/main.cpp)

setup_geode_mod(FrameAssist)
