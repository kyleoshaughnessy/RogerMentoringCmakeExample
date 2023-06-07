cmake_minimum_required(VERSION 3.11)

project(
    RogerTest
    VERSION 0.0.1
    DESCRIPTION "Roger C++ Learning"
    LANGUAGES CXX
)

add_executable(test_app
    src/main.cpp
    src/funcs.cpp
    include/funcs.h
)

set_target_properties(test_app PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(test_app PROPERTIES CXX_STANDARD 20)

target_include_directories(test_app PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

if (MSVC)
    target_compile_options(test_app PRIVATE /W4 /WX)
else()
    target_compile_options(test_app PRIVATE -Wall -Wextra -Wpedantic -Werror -Wmissing-declarations -Wdeprecated -Wshadow)
endif()
