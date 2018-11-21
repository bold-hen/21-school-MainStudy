# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 20:45:26 by bold-hen          #+#    #+#              #
#    Updated: 2018/09/04 17:10:54 by bold-hen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

DIR= includes

all: $(NAME)
$(NAME): srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
	ar rc $(NAME) $^
srcs/ft_putchar.o: srcs/ft_putchar.c
	gcc -Wall -Wextra -Werror -I$(DIR) -c -o $@ $<
srcs/ft_putstr.o: srcs/ft_putstr.c
	gcc -Wall -Wextra -Werror -I$(DIR) -c -o $@ $<
srcs/ft_strcmp.o: srcs/ft_strcmp.c
	gcc -Wall -Wextra -Werror -I$(DIR) -c -o $@ $<
srcs/ft_strlen.o: srcs/ft_strlen.c
	gcc -Wall -Wextra -Werror -I$(DIR) -c -o $@ $<
srcs/ft_swap.o: srcs/ft_swap.c
	gcc -Wall -Wextra -Werror -I$(DIR) -c -o $@ $<
clean:
	rm -f srcs/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all
