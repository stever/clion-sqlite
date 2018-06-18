cmake_minimum_required(VERSION 3.10)
project(CLionSQLite C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} main.c)

include_directories(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/libs/sqlite3.dll")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/libs" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
