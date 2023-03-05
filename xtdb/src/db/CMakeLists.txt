add_library(
	xtdb
        STATIC
        xttablepage.cpp
        xtobjectpage.cpp
        xtshape.cpp
        xttech.cpp
        xtcolor.cpp
        xtrectangle.cpp
        xtblock.cpp
        xtcore.cpp
        xtshape.cpp
)
add_custom_target(headers_xtdb SOURCES
    xthashtable.h
    _xtblock.h
    xttable.h
    xttable.hpp
    xthashtable.hpp
    xtcore.h
    xttablepage.h
    xtobjectpage.h
    _xtshape.h
    _xttech.h
    _xtrectangle.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtset.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtrectangle.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtsize.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtcolor.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtiterator.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtblock.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtshape.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtdb.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtiterator.hpp
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtset.hpp
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtcontainer.h
    ${PROJECT_SOURCE_DIR}/xtdb/include/xtobject.h
)
target_include_directories(
        xtdb
        PRIVATE
        ${PROJECT_SOURCE_DIR}/xtdb/src/db
        ${PROJECT_SOURCE_DIR}/xtdb/src/common
)
target_include_directories(xtdb PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/xtdb/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS xtdb EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/xtdb/include DESTINATION ${CMAKE_INSTALL_PREFIX})
install(EXPORT xtdbTargets
        FILE xtdbConfig.cmake 
        DESTINATION lib/xtdb)
