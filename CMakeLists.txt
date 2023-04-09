cmake_minimum_required(VERSION 3.23)
project(ForIsPritchin C)

set(CMAKE_C_STANDARD 99)

add_executable(ForIsPritchin main.c)

add_library(data_structures
        libs/data_structures/vector/vector.c
)

target_link_libraries(ForIsPritchin data_structures)