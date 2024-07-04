cmake_minimum_required(VERSION 3.16)

project(pazaak)

include_directories(../..)

aux_source_directory(../src SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic -g -std=c++20")

add_compile_definitions(_DEBUG)
