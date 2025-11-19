cmake_minimum_required(VERSION 3.12)
project(Lab3Task6)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bracket main.c func.c)

target_include_directories(bracket PRIVATE include)