add_library(exttests STATIC ${CMAKE_CURRENT_SOURCE_DIR}/xtset-tests.cpp)
target_include_directories(exttests PUBLIC
    ${XTDB_INST_DIR}/include)
target_include_directories(exttests PUBLIC
    ${PROJECT_SOURCE_DIR}/xtdb-test)
target_link_directories(exttests PUBLIC
    ${XTDB_INST_DIR}/lib)
target_link_libraries(exttests PUBLIC
    xtdb)
