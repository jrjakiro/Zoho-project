cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(DoublyLinkedList)

add_executable(
    sample
    header.h
    main.cpp
    push.cpp
    printvalues.cpp
    append.cpp
    insert.cpp
    size.cpp
    delete.cpp

)