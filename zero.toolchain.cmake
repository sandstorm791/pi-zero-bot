#i dont even care bro just compile

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(SYSROOT_PATH "$ENV{SYSROOT_PATH}")
if(NOT SYSROOT_PATH)
	set(SYSROOT_PATH "$ENV{PWD}../sysroot")
endif()
set(CMAKE_SYSROOT ${SYSROOT_PATH})

set(CMAKE_C_COMPILER clang)

add_compile_options(
    -target arm-linux-gnueabihf
    -mcpu=arm1176jzf-s
    -mfloat-abi=hard
    -D__arm__=1
    -U__x86_64__
)

set(FLAGS "-target arm-linux-gnueabihf -mcpu=arm1176jzf-s -mfloat-abi=hard --rtlib=compiler-rt -fuse-ld=lld -D__arm__=1 -U__x86_64__ -isystem ${SYSROOT_PATH}/usr/include/arm-linux-gnueabihf -isystem ${SYSROOT_PATH}/usr/include")

set(CMAKE_C_FLAGS "${FLAGS}" CACHE STRING "" FORCE)

set(LINK_FLAGS "-B${SYSROOT_PATH}/usr/lib/arm-linux-gnueabihf -B${SYSROOT_PATH}/lib/arm-linux-gnueabihf")
set(CMAKE_EXE_LINKER_FLAGS "${LINK_FLAGS}" CACHE STRING "" FORCE)

set(CMAKE_FIND_ROOT_PATH ${SYSROOT_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

