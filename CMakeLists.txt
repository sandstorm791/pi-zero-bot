cmake_minimum_required(VERSION 3.20)
project(robot_thing_yeah C)

set(CMAKE_C_STANDARD 17)

add_executable(brain main.c)

set(SYSROOT_PATH "$ENV{SYSROOT_PATH}")
if(NOT SYSROOT_PATH)
	set(SYSROOT_PATH "$ENV{PWD}/../sysroot")
endif()

target_include_directories(brain SYSTEM PRIVATE 
    "${SYSROOT_PATH}/usr/include/arm-linux-gnueabihf"
    "${SYSROOT_PATH}/usr/include"
)

