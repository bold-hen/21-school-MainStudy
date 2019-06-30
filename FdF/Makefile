#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 11:57:00 by bold-hen          #+#    #+#              #
#    Updated: 2019/01/26 11:31:50 by bold-hen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= fillit
LIB= libft
LIBNAME= libft.a
SCR= libft/*.c
INC= libft/includes
GCC= gcc -Wall -Wextra -Werror
OBJ= $(patsubst %.c, %.o, $(wildcard *.c))

all: $(NAME)

$(NAME): $(LIB)

$(LIB): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(GCC) -c -I $(INC) $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
