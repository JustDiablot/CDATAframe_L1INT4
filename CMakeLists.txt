cmake_minimum_required(VERSION 3.27)
project(CDATAframe_L1INT4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CDATAframe_L1INT4
        main.c
        column.c
        CDATA.c
        modify.c
)
