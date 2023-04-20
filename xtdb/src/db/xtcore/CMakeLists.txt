add_library(
    xtcore OBJECT
    xtobjectpage.cpp
    xttablepage.cpp
    xtobject.cpp
    xtcore.cpp
)
target_include_directories(
    xtcore PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb/src/db
    ${PROJECT_SOURCE_DIR}/xtdb/include
    ${PROJECT_SOURCE_DIR}/xtdb/src/common
)
target_link_libraries(
    xtcore PUBLIC
    common
)
add_custom_target(
    headers_xtcore SOURCES
    xthashtable.h
    xtobjectpage.h
    xttable.h
    xttablepage.h
)
install(TARGETS xtcore EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)
