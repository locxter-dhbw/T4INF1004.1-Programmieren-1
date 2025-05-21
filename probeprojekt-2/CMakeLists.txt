cmake_minimum_required(VERSION 3.30)
project(probeprojekt_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(probeprojekt_2 main.c
        bitmap.c
        bitmap.h
)

target_link_libraries(${PROJECT_NAME} m)