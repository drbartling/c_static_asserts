cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(simple_example)

# ---- Create binary ----

add_executable(${PROJECT_NAME} src/main.c)

# ---- Run executable ----
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
