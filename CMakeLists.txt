cmake_minimum_required(VERSION 3.8)


project(
    CPlusPlusBestC 
    LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -O3")
    
add_executable(main main.cpp )