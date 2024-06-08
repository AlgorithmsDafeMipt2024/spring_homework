cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE lib_source_list "src/*.cpp" "src/*.hpp")

add_library(Utils ${lib_source_list})

target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
