/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:35:50 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 12:04:34 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrlen(int n)
{
	int length;

	length = 0;
	if (n < 0)
		length = 1;
	while (n / 10 != 0)
	{
		length++;
		n = n / 10;
	}
	return (length + 2);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = ft_arrlen(n);
	res = (char *)malloc(sizeof(char) * i);
	if (res == NULL)
		return (NULL);
	res[--i] = '\0';
	if (n < 0)
		res[0] = '-';
	while (n / 10 != 0)
	{
		if (n < 0)
			res[--i] = -(n % 10) + '0';
		else
			res[--i] = n % 10 + '0';
		n = n / 10;
	}
	if (n < 0)
		res[--i] = -(n % 10) + '0';
	else
		res[--i] = n % 10 + '0';
	return (res);
}
