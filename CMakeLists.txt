cmake_minimum_required(VERSION 3.10)

project(c-snake-game C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UBSan in Debug builds (GCC/Clang)" ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>: /W4 /WX /Zi /Od /RTC1>
        $<$<CONFIG:Release>: /W4 /WX /O2 /GL /DNDEBUG>
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:/LTCG>
    )
else()
    set(DEBUG_SANITIZER_COMPILE_FLAGS "")
    set(DEBUG_SANITIZER_LINK_FLAGS "")

    if(ENABLE_SANITIZERS)
        set(DEBUG_SANITIZER_COMPILE_FLAGS -fsanitize=address,undefined -fno-omit-frame-pointer)
        set(DEBUG_SANITIZER_LINK_FLAGS -fsanitize=address,undefined)
    endif()

    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>: -Wall -Wextra -Werror -g -O0 -DDEBUG_BUILD
        ${DEBUG_SANITIZER_COMPILE_FLAGS}>
        $<$<CONFIG:Release>: -O3 -DNDEBUG>
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>: ${DEBUG_SANITIZER_LINK_FLAGS}>
        $<$<CONFIG:Release>: -s>
    )
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")