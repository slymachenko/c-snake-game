add_library(project_warnings INTERFACE)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(project_warnings INTERFACE
        -Wall
        -Wextra
        -Wpedantic

        -Wconversion
        -Wsign-conversion
        -Wshadow

        -Wstrict-prototypes
        -Wmissing-prototypes
        -Wold-style-definition

        -Wformat=2
        -Wundef
        -Wvla
        -Wswitch-enum
        -Wimplicit-fallthrough

        -Wcast-qual
        -Wpointer-arith
        -Wwrite-strings

        -Werror
    )
else()
    message(
        FATAL_ERROR
        "Unsupported compiler: ${CMAKE_C_COMPILER_ID}"
    )
endif()
