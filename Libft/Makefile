#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 11:57:00 by bold-hen          #+#    #+#              #
#    Updated: 2018/11/21 12:33:30 by bold-hen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= libft.a
SCR= *.c
GCC= gcc -Wall -Wextra -Werror -c
OBJ= $(patsubst %.c, %.o, $(wildcard *.c))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(GCC) $<

clean:
	rm *.o

fclean: clean
	rm $(NAME)

re: fclean all