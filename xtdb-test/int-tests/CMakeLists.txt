add_library(inttests STATIC ${CMAKE_CURRENT_SOURCE_DIR}/stream-tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/xttable-tests.cpp)
target_include_directories(inttests PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb/src/common
    ${PROJECT_SOURCE_DIR}/xtdb/src/db)
target_include_directories(inttests PUBLIC
    ${PROJECT_SOURCE_DIR}/xtdb-test)
target_link_libraries(inttests PRIVATE
    xtdb)
