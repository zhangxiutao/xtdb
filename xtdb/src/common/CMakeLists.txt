add_library(
	common
	xtexception.cpp
)
add_custom_target(headers_common SOURCES
    xtstream.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtexception.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xttypes.h)
target_include_directories(
	common
        PRIVATE
	${PROJECT_SOURCE_DIR}/xtdb/src/common
)
target_include_directories(
        common
        PRIVATE
        ${PROJECT_SOURCE_DIR}/xtdb/include
)

