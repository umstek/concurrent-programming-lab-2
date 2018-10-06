cmake_minimum_required(VERSION 3.12)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)

find_package(Threads REQUIRED)
add_executable(LinkedList main.c linked_list.c test_generator.c mutex_facility.c rwl_facility.c serial_facility.c)
target_link_libraries(LinkedList ${CMAKE_THREAD_LIBS_INIT})
