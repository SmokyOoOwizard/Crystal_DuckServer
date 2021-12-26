cmake_minimum_required(VERSION 3.16)
project(Crystal_DuckServer)

set(CMAKE_CXX_STANDARD 20)

string(TIMESTAMP BUILD_START_UNIX_TIME "%s")
set(BUILD_TIME ${BUILD_START_UNIX_TIME})

if(NOT DEFINED ${BUILD_CONDITION})
    set(BUILD_CONDITION Dev)
endif()

configure_file("src/ApplicationInfoDefines.h.in" "${PROJECT_SOURCE_DIR}/src/ApplicationInfoDefines.h.out" @ONLY)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(CrystalServer ${SRC_FILES})