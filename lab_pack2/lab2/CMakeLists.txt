cmake_minimum_required(VERSION 3.12)
project(Lab2Task2)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(funcs main.c func.c
)

target_include_directories(funcs PRIVATE include)

target_compile_options(funcs PRIVATE -fno-builtin)