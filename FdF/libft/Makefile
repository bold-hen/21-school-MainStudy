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

NAME= libft.a
SCR= *.c
INC= includes
GCC= gcc -Wall -Wextra -Werror
OBJ= $(patsubst %.c, %.o, $(wildcard *.c))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(GCC) -c -I $(INC) $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
