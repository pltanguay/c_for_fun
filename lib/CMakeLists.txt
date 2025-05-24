project(lib)

add_library(libUtils STATIC
    src/hello.c
    src/allocate.c
    src/wait.c
    src/memory_map.c
    src/circular_buffer.c
)

target_include_directories(libUtils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)