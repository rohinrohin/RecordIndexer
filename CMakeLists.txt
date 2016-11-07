cmake_minimum_required(VERSION 3.6)
project(RecordIndexer)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES bplus.c)
add_executable(RecordIndexer ${SOURCE_FILES})