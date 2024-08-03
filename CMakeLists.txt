cmake_minimum_required(VERSION 3.10)

# Project name
project(CPU_simulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Source files
set(SOURCES
    main.cpp
    cpu.cpp
    memory.cpp
    ram.cpp
    rom.cpp
    instruction.cpp
    factory.cpp
    jump.cpp
    exit.cpp
    add.cpp
    addi.cpp
    print.cpp
    set.cpp
    runner.cpp
)

# Add executable
add_executable(CPU_simulator ${SOURCES})

