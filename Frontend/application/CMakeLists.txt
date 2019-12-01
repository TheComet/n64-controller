add_executable (n64c-config
    "src/main.c")
target_link_libraries (n64c-config
    PRIVATE
        n64c)
