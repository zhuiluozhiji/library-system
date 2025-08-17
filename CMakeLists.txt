cmake_minimum_required(VERSION 3.10)
project(library-system)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SRC_FILES src/*.cpp)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_executable(library-system ${SRC_FILES})