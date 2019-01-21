/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:39:14 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 16:17:55 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    unsigned char result[2];
    unsigned char b = (unsigned char)c;

    if (c < 0)
    {
		result[0] = 192 + 2 * (b / 128) + ((b % 128) / 64);
		result[1] = 128 + b % 64;
		write(fd, result, 2);
    }
    else 
		write(fd, &c, 1);
}
