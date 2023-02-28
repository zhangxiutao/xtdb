add_executable(all-tests main.cpp)
add_subdirectory(int-tests)
add_subdirectory(ext-tests)
target_link_directories(all-tests PRIVATE
    ${PROJECT_BINARY_DIR}/xtdb-test/int-tests)
target_link_directories(all-tests PRIVATE
    ${PROJECT_BINARY_DIR}/xtdb-test/ext-tests)
#the following two lines enable test cases in static library to be found
target_link_libraries(all-tests -Wl,--whole-archive inttests -Wl,--no-whole-archive)
target_link_libraries(all-tests -Wl,--whole-archive exttests -Wl,--no-whole-archive)

