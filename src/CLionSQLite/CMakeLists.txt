cmake_minimum_required(VERSION 3.10)
project(CLionSQLite C)

set(CMAKE_C_STANDARD 11)

add_library(CLionSQLite SHARED library.c library.h)

include(GenerateExportHeader)
generate_export_header(CLionSQLite)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBUILDING_CLIONSQLITE_LIBRARY")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --subsystem,windows")