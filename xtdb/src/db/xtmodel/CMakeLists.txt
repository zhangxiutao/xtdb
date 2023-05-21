add_library(
    xtmodel OBJECT
    xtshape.cpp
    xtrectangle.cpp
    xtblock.cpp
    xtshape.cpp
    xtnet.cpp
    xtwireseg.cpp
    xtinst.cpp
    xtvia.cpp
    xteobject.cpp
    xtnetobject.cpp
    xtquery.cpp
    xtshapequery.cpp
    xtport.cpp
    xtportinst.cpp
    xtline.cpp
)
target_link_libraries(
    xtmodel PRIVATE
    xtcore
    xtdm
    common
)
target_include_directories(
    xtmodel PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb/include
    ${PROJECT_SOURCE_DIR}/xtdb/src/db
    ${PROJECT_SOURCE_DIR}/xtdb/src/db/xtcore
    ${PROJECT_SOURCE_DIR}/xtdb/src/db/xtmodel
    ${PROJECT_SOURCE_DIR}/xtdb/src/db/xtdm
    ${PROJECT_SOURCE_DIR}/xtdb/src/common
)
add_custom_target(
    headers_xtmodel SOURCES
    _xtnetobject.h
    _xteobject.h
    _xtvia.h
    _xtwireseg.h
    _xtblock.h
    _xtshape.h
    _xtrectangle.h
    _xtport.h
    _xtportinst.h
    _xtline.h
    _xtinst.h
    xtpccontainer.h
    xttypemap.h
)
install(TARGETS xtmodel EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)
