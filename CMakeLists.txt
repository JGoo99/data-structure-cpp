cmake_minimum_required(VERSION 3.27)
project(array)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        packedUnsorted
        array/_01/packedUnsorted.cpp
)

add_executable(
        packedSorted
        array/_02/packedSorted.cpp
)

add_executable(
        unpackedUnsorted
        array/_03/unpackedUnsorted.cpp
)

