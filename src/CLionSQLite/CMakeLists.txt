cmake_minimum_required(VERSION 3.5.1) # NOTE: Ubuntu 16.04 LTS provides CMake 3.5.1
project(CLionSQLite C)

set(CMAKE_C_STANDARD 11)

add_library(CLionSQLite SHARED library.c library.h)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy 
	${PROJECT_SOURCE_DIR}/library.h 
	${PROJECT_SOURCE_DIR}/../../include)

if (NOT WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy 
		${CMAKE_CURRENT_BINARY_DIR}/libCLionSQLite.so 
		${PROJECT_SOURCE_DIR}/../../libs)
else ()
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy 
		${CMAKE_CURRENT_BINARY_DIR}/libCLionSQLite.dll
		${PROJECT_SOURCE_DIR}/../../libs/CLionSQLite.dll)
endif ()

