cmake_minimum_required(VERSION 3.11)
project(Argz)

set(CMAKE_CXX_STANDARD 11)

# BOOST
if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR )
    # stand-alone build
    find_package(Boost 1.77 REQUIRED COMPONENTS algorithm)
    message(STATUS "Boost version: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})

else()

endif()

#
include_directories(include)
add_library(Argz src/Argz/Args.cc)
target_link_libraries(Argz Boost::algorithm)
