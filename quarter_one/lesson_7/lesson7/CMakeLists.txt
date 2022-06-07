cmake_minimum_required(VERSION 3.5)

project(lesson7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lesson7 main.cpp mylib.cpp co_worker.cpp co_worker.h mylib.h)
