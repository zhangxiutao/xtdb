add_library(
    xtdm OBJECT
    xtdm.cpp
)
add_custom_target(
    headers_xtdm SOURCES
    xtdm.h
)
install(TARGETS xtdm EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)

