set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv64)
set(CMAKE_SYSTEM_VERSION "0.0.0")

set(CMAKE_CROSSCOMPILING TRUE)

set(CMAKE_OSX_ARCHITECTURES "")

set(CMAKE_C_COMPILER riscv64-unknown-elf-gcc) 
set(CMAKE_LINKER riscv64-unknown-elf-ld)

set(CMAKE_C_FLAGS "-march=rv64gcv") 
set(CMAKE_C_LINK_EXECUTABLE
        "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_C_LINK_FLAGS> <LINK_FLAGS> \"${CRTI_OBJ}\" \"${CRTBEGIN_OBJ}\" <OBJECTS> \"${CRTEND_OBJ}\" \"${CRTN_OBJ}\" -o <TARGET> <LINK_LIBRARIES>")

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
