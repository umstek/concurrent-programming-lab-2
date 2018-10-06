cmake_minimum_required(VERSION 3.12)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)

find_package(Threads REQUIRED)
add_executable(LinkedList linked_list.c main.c)
target_link_libraries(LinkedList ${CMAKE_THREAD_LIBS_INIT})
