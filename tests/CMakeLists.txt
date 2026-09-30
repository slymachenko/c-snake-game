add_executable(c_project_tests
    test_main.c
)

target_link_libraries(c_project_tests
    PRIVATE
        project_warnings
        project_sanitizers
)

add_test(
    NAME c_project_tests
    COMMAND c_project_tests
)
