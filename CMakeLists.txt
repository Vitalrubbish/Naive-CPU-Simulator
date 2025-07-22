cmake_minimum_required(VERSION 3.22)
project(CPU_Simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(NaiveSimulator)

add_executable(CPU_Simulator
    include/Instruction.h
    include/Executor.h
    main.cpp
    include/Memory.h
    utility/utility.h
    utility/InputManager.h
)
