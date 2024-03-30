cmake_minimum_required(VERSION 3.27)
project(array/_01)

set(CMAKE_CXX_STANDARD 17)

add_executable(array/_01 array/_01/packedUnsorted.cpp
        array/_02/packedSorted.cpp
        array/_03/unpackedUnsorted.cpp
)
