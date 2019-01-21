/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:35:50 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/19 11:55:00 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_arrlen(int n)
{
	int length;

	length = 0;
	if(n < 0)
		length = 1;
    while(n / 10 != 0)
    {
        length++;
        n = n / 10;
    }
	return (length + 2);
}

char *ft_itoa(int n)
{
	char *res;
	int index;

	index = ft_arrlen(n);
	res = (char *)malloc(sizeof(char) * index);
	if (res == NULL)
		return (NULL);
	res[--index] = '\0';
	if (n < 0)
		res[0] = '-';
	while(n / 10 != 0)
	{
		n < 0 ? res[--index] = -(n % 10) + '0' : (res[--index] = n % 10 + '0');
		n = n / 10;
	}
    n < 0 ? res[--index] = -n % 10 + '0' : (res[--index] = n % 10 + '0');
	return (res);
}
