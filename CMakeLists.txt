cmake_minimum_required(VERSION 3.27.0)
project(
    CForFun
    LANGUAGES C
    VERSION 1.0
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(utils)

add_executable(CForFun
    main.c
)

target_link_libraries(CForFun PRIVATE Utils)
