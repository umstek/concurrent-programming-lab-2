cmake_minimum_required(VERSION 3.12)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(LinkedList main.c linked_list.h)