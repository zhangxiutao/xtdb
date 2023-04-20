add_library(
    common OBJECT
    xtexception.cpp
    xtopermat.cpp
)
add_custom_target(
    headers_common SOURCES
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtexception.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xttypes.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtpoint.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtopermat.h
)
target_include_directories(
    common PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb/src/common
)
target_include_directories(
    common PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb/include
)

install(TARGETS common EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)
