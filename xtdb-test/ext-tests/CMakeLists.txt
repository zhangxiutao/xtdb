add_library(exttests STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/xtset-tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/destroy-tests.cpp)
target_include_directories(exttests PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb-test)
target_link_libraries(exttests PUBLIC
    xtdb)
