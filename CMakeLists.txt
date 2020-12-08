cmake_minimum_required(VERSION 3.10)

project(programa)

set(CMAKE_CXX_STANDARD 11)

add_executable(programa 
    
    src/palavra.cpp
    src/palavraerrada.cpp
    src/main.cpp
)

target_include_directories(programa PUBLIC "include")