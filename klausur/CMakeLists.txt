cmake_minimum_required(VERSION 3.30)
project(klausur C)

set(CMAKE_C_STANDARD 99)

add_executable(klausur main.c
        bitmap.c
        bitmap.h)

target_link_libraries(${PROJECT_NAME} m)