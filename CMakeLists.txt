cmake_minimum_required(VERSION 3.0)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

find_package(Threads REQUIRED)
add_executable(LinkedList main.c linked_list.c test_generator.c mutex_facility.c rwlock_facility.c serial_facility.c timer.h)
target_link_libraries(LinkedList pthread)
