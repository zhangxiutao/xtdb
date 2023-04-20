add_subdirectory(xtcore)
add_subdirectory(xtmodel)
add_library(
    xtdb STATIC
    xttech.cpp
)
target_link_libraries(
    xtdb PUBLIC
    xtmodel
    xtcore
)
target_include_directories(
   xtdb PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/xtdb/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS xtdb EXPORT xtdbTargets
        ARCHIVE DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/xtdb/include DESTINATION ${CMAKE_INSTALL_PREFIX})
install(EXPORT xtdbTargets
        FILE xtdbConfig.cmake
        DESTINATION lib/xtdb)
