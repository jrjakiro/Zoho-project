cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")


project(DoublyLinkedList)

add_executable(
    doubly_linked_list
    main.cpp
)

find_package(Catch2 REQUIRED)
add_executable(
    tester 
    catch_amalgamated.cpp 
    test.cpp
)
target_link_libraries(tester PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tester)

