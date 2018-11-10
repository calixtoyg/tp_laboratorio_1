cmake_minimum_required(VERSION 3.12)
project(utn_tp3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(utn_tp3
        Controller.c
        Controller.h
        data.csv
        Employee.c
        Employee.h
        LinkedList.a
        LinkedList.h
        LinkedList.c
        functionsForProjects.c
        functionsForProjects.h
        main.c
        parser.c
        parser.h)
target_link_libraries(utn_tp3 ${CMAKE_SOURCE_DIR}/LinkedList.a)