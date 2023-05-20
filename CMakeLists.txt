cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(c_static_asserts)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE src)
