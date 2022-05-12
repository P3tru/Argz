cmake_minimum_required(VERSION 3.11)
project(Argz)

set(CMAKE_CXX_STANDARD 11)

# BOOST
find_package(Boost 1.70 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIRS})

#
include_directories(include)
add_library(Argz src/Args.cc)
