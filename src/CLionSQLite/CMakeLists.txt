cmake_minimum_required(VERSION 3.10)
project(CLionSQLite C)

set(CMAKE_C_STANDARD 11)

add_library(CLionSQLite SHARED library.c library.h)
