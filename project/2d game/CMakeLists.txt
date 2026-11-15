
cmake_minimum_required(VERSION 3.28)

project(CppSandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW TRUE
)

if(UNIX)
    message(STATUS "Building for Linux")
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
endif()


FetchContent_MakeAvailable(SFML)

add_executable(CppSandbox
    src/main.cpp
    src/Player/player.cpp
)

target_link_libraries(CppSandbox PRIVATE SFML::Graphics)
