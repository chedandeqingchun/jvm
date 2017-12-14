cmake_minimum_required(VERSION 3.5.1)
project(jvm)

set(CMAKE_C_COMPILER "g++")
add_definitions(-std=c++11)


set(source_files
  main.cpp 
  jvm_cli.cpp
  load_class.cpp
)

add_executable(jvm ${source_files})
