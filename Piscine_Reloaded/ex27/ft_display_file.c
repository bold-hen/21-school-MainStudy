/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:10:26 by bold-hen          #+#    #+#             */
/*   Updated: 2018/11/20 21:10:15 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_read_file(char *filename)
{
	int		r;
	char	buff[256];
	int		length;

	r = open(filename, O_RDONLY);
	while ((length = read(r, buff, 256)))
		write(1, buff, length);
	close(r);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "File name missing.\n", 19);
	else	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
		ft_read_file(argv[1]);
	return (0);
}
