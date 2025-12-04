cmake_minimum_required(VERSION 3.12)
project(Lab1Task2)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(func main.c func.c)

target_include_directories(func PRIVATE include)