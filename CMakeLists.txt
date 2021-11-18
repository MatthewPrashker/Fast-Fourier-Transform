cmake_minimum_required(VERSION 3.20)
project(array)

set(CMAKE_CXX_STANDARD 14)

add_executable(array src/main.cpp src/array.cpp)
set_target_properties(array PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
