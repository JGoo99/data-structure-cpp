cmake_minimum_required(VERSION 3.27)
project(_01)

set(CMAKE_CXX_STANDARD 17)

add_executable(_01 _01/packedUnsorted.cpp
        _02/packedSorted.cpp
        _03/unpackedUnsorted.cpp
)
