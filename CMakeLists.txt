cmake_minimum_required(VERSION 3.5)

project(xtdb LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(XTDB_INST_DIR xtdbInstDir)

add_subdirectory(xtdb)
add_subdirectory(xtdb-test)

