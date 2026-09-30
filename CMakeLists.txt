cmake_minimum_required(VERSION 3.25)

project(
    c_snake_game
    VERSION 0.1.0
    DESCRIPTION "C Snake Game"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CompilerWarnings)
include(Sanitizers)

add_executable(${PROJECT_NAME}
    src/main.c
    src/renderer/renderer_tui.c
    src/updater/updater.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        project_warnings
        project_sanitizers
)

add_subdirectory(tests)