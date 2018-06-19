cmake_minimum_required(VERSION 3.5) # NOTE: Ubuntu 16.04 LTS provides CMake 3.5.1
project(CLionSQLite_Cmd C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
        main.c
        lua.c lua.h
        sqlite.c sqlite.h
        openmp.c openmp.h
        )

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

if (NOT WIN32)
    # sudo apt install sqlite3 libsqlite3-dev
    # sudo apt install lua5.1 liblua5.1-0-dev
    target_link_libraries(${PROJECT_NAME} LINK_PUBLIC sqlite3)
    target_link_libraries(${PROJECT_NAME} LINK_PUBLIC lua5.1)
else ()
    # NOTE: WIN32 is true if Windows is either 32-bit or 64-bit.
    include_directories(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/../../include")
    target_link_libraries(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/sqlite3.dll")
    target_link_libraries(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/lua5.1.dll")

    # Copy the DLLs to the build output folder.
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/../../libs" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif ()
