aux_source_directory(ext-tests EXT_TESTS_SRC)
aux_source_directory(int-tests INT_TESTS_SRC)
add_executable(all-tests main.cpp ${EXT_TESTS_SRC} ${INT_TESTS_SRC})
target_link_libraries(all-tests PRIVATE xtdb)
target_include_directories(
        all-tests
        PRIVATE
        ${PROJECT_SOURCE_DIR}/xtdb/src/db
        ${PROJECT_SOURCE_DIR}/xtdb/src/common
)
target_include_directories(
        all-tests
        PRIVATE
        ${PROJECT_SOURCE_DIR}/xtdb-test
)
