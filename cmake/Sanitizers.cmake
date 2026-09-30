option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

add_library(project_sanitizers INTERFACE)

if(ENABLE_SANITIZERS)
    if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(project_sanitizers INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
            -g
        )

        target_link_options(project_sanitizers INTERFACE
            -fsanitize=address,undefined
        )
    else()
        message(
            FATAL_ERROR
            "Sanitizers are not configured for this compiler"
        )
    endif()
endif()
