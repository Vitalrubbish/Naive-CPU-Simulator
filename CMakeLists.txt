cmake_minimum_required(VERSION 3.22)
project(code)

set(CMAKE_CXX_STANDARD 14)

include_directories(NaiveSimulator)

add_executable(code
    include/Instruction.h
    include/Executor.h
    include/InputManager.h
    include/Memory.h
    include/Register.h
    src/Instruction.cpp
    utility/utility.h
    main.cpp
)
