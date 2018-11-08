cmake_minimum_required(VERSION 3.12)
project(Win_64)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Win_64
        Controller.c
        Controller.h
        data.csv
        Employee.c
        Employee.h
        LinkedList.a
        LinkedList.h
        main.c
        parser.c
        parser.h LinkedList.c)
