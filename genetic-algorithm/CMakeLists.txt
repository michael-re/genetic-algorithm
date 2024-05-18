cmake_minimum_required(VERSION 3.20)
project(ga)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BINARY_DIR        ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/bin)

file(GLOB ga_inc_files include/ga/*.hpp)
file(GLOB ga_src_files source/ga/*.cpp)

add_executable(ga ${ga_src_files} ${ga_inc_files})
target_include_directories(ga PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
