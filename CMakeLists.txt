cmake_minimum_required(VERSION 3.16)
project(Crystal_DuckServer)

set(CMAKE_CXX_STANDARD 20)

string(TIMESTAMP BUILD_START_UNIX_TIME "%s")
set(BUILD_TIME ${BUILD_START_UNIX_TIME})

if(NOT DEFINED ${BUILD_CONDITION})
    set(BUILD_CONDITION Dev)
endif()

configure_file("src/ApplicationInfoDefines.h.in" "${PROJECT_SOURCE_DIR}/src/ApplicationInfoDefines.h.out" @ONLY)

set(SRC_FILES
        "src/main.cpp"
        "src/ApplicationInfo.cpp"
        "src/ApplicationSettings.cpp"
        "src/Butler.cpp"
        "src/ConductorConnections.cpp"
        "src/Networks/NetworkBase.cpp"
        "src/Networks/TcpNetwork.cpp"
        "src/Networks/NetworkConnectionBase.cpp"
        "src/Networks/TcpNetworkConnection.cpp")

add_executable(CrystalDuckServer ${SRC_FILES})

if(WIN32)
    target_link_libraries(CrystalDuckServer wsock32 ws2_32)
endif()