cmake_minimum_required(VERSION 3.5)

project(jmath VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB_RECURSE jmath_headers "include/**.hpp")
file(GLOB_RECURSE jmath_sources "src/**.cpp")
add_library(jmath ${jmath_headers} ${jmath_sources})
target_include_directories(jmath PUBLIC include include/jmath)

add_subdirectory(examples/constant)