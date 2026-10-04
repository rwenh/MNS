cmake_minimum_required(VERSION 3.10)
project(dsa_learning C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Public headers live in include/
include_directories(${CMAKE_SOURCE_DIR}/include)

# Core library sources
set(DSA_SOURCES
    src/array_ops.c
    src/recursion.c
    src/stack_queue.c
    src/linked_list.c
    src/trees_bst.c
    src/heap.c
    src/graph.c
)

add_library(dsa_core STATIC ${DSA_SOURCES})

# Driver executable
add_executable(dsa_runner examples/main.c)
target_link_libraries(dsa_runner PRIVATE dsa_core)

# Optional install rules
install(TARGETS dsa_runner dsa_core
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/dsa DESTINATION include)
