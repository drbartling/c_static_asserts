cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(simple_example)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# include(../../cmake/CPM.cmake)

# if(NOT TARGET c_static_asserts)
#     CPMAddPackage("gh:drbartling/c_static_asserts#master")
# endif()
add_subdirectory(../.. lib_build)

# ---- Create binary ----

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE c_static_asserts)

# ---- Run executable ----
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
