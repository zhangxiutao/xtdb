add_library(
    xtdm OBJECT
    xtdm.cpp
)
target_include_directories(
    xtdm PRIVATE
    ${PROJECT_SOURCE_DIR}/xtdb/include
)
install(TARGETS xtdm EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)

