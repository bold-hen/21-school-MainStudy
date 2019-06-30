cmake_minimum_required(VERSION 3.12)
project(FdF C)

set(CMAKE_C_STANDARD 99)

add_executable(FdF main.c FdF.h minilibx_macos/mlx.h)
add_library(minilibx_macos/libmlx.a)
add_compile_options(-I minilibx_macos/  main.c -L minilibx_macos -lmlx -framework OpenGL -framework AppKit)