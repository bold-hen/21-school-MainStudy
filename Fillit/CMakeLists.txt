cmake_minimum_required(VERSION 3.12)
project(Fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(Fillit main.c Fillit.h libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_strnew.c libft/ft_bzero.c libft/ft_memmove.c libft/ft_lstdel.c libft/ft_lstnew.c libft/ft_strlen.c libft/ft_strsplit.c libft/ft_lstdelone.c libft/ft_memcpy.c libft/ft_putchar.c)
include_directories(libft)