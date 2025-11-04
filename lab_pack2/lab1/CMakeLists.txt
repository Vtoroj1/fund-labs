cmake_minimum_required(VERSION 3.12)
project(Lab2Task1)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(checker main.c func.c)

target_include_directories(checker PRIVATE include)