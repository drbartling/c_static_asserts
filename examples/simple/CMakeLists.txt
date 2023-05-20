cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(simple_example)

include(../../cmake/CPM.cmake)

if(NOT TARGET c_static_asserts)
    CPMAddPackage("gh:drbartling/c_static_asserts#master")
endif()

# ---- Create binary ----

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE c_static_asserts)

# ---- Run executable ----
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
