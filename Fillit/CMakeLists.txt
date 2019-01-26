cmake_minimum_required(VERSION 3.12)
project(Fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(Fillit main.c Fillit.h)
include_directories(libft)