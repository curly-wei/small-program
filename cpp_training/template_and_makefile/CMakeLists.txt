cmake_minimum_required(VERSION 3.8)

project(tmp_lib)
add_library(tmp_lib SHARED tmp.cc)

project(tmp_exec)
add_executable(tmp_exec main.cc)
target_link_libraries(tmp_exec tmp_lib)