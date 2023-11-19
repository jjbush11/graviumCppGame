cmake_minimum_required(VERSION 3.15)
project(Gravium)

set(CMAKE_CXX_STANDARD 17)

add_executable(M1OP main.cpp
        Hero.cpp
        Villain.h
        Villain.cpp
        GameOperation.h
        GameOperation.cpp
        Character.h
        Character.cpp)
