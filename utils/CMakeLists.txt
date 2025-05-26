project(Utils)

add_library(Utils STATIC
    src/hello.c
    src/allocate.c
    src/wait.c
    src/memory_map.c
    src/circular_buffer.c
    src/fixed_point_arithmetic.c
    src/bit.c
    src/debouncing.c
)

target_include_directories(Utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Utils m)