add_library(
	common
	xtexception.cpp
)
add_custom_target(headers_common SOURCES xtexception.h xtstream.h xttypes.h)
target_include_directories(
	common
	PUBLIC
	${PROJECT_SOURCE_DIR}/xtdb/src/common
)
