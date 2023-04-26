cmake_minimum_required(VERSION 3.11)
project(Argz)

set(CMAKE_CXX_STANDARD 11)

#
include_directories(include)
add_library(Argz src/Argz/Args.cc)
