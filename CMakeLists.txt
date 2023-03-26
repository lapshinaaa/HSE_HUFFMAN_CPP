cmake_minimum_required(VERSION 3.23.2)
project(HSE_HUFFMAN_CPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(HSE_HUFFMAN_CPP main.cpp Decompress/decompress.cpp Decompress/decompress.h Compress/Compress.cpp Compress/Compress.h Compress/tests.cpp gui.cpp)
