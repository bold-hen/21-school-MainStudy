# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 20:45:26 by bold-hen          #+#    #+#              #
#    Updated: 2018/11/20 19:46:17 by bold-hen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_display_file

DIR= includes

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(NAME).c 
clean:
	rm -f srcs/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all
