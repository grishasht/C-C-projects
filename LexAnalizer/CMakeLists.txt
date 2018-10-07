cmake_minimum_required(VERSION 3.10)
project(LexAnalizer)

set(CMAKE_CXX_STANDARD 11)

include_directories(LexAnalizer)

add_executable(LexAnalizer
        LexAnalizer/CorTest.txt
        LexAnalizer/Functions.cpp
        LexAnalizer/Functions.h
        LexAnalizer/Lex.txt
        LexAnalizer/Test.asm
        LexAnalizer/test.cpp)
