add_executable(all-tests main.cpp stream-tests.cpp xttable-tests.cpp)
target_include_directories(all-tests PUBLIC
    ${PROJECT_SOURCE_DIR}/xtdb/src/common
    ${PROJECT_SOURCE_DIR}/xtdb/src/db)
target_link_directories(all-tests PUBLIC
    ${PROJECT_SOURCE_DIR}/xtdb/src/db)
target_link_libraries(all-tests PUBLIC
    xtdb)
