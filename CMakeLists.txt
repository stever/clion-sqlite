cmake_minimum_required(VERSION 3.5)
project(CLionSQLite C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} main.c)

if (WIN32) # true if windows (32 and 64 bit)
    include_directories(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/include")
    target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/libs/sqlite3.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/libs" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
else()
    target_link_libraries(${PROJECT_NAME} LINK_PUBLIC sqlite3)
    find_package(Lua51 REQUIRED)
    target_link_libraries(${PROJECT_NAME} LINK_PUBLIC lua5.1)
endif()
