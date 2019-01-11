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
	{
		length = 1;
		n = n * -1;
	}
    while(n / 10 > 0 || n % 10 > 0)
	{
		length++;
		n = n / 10;
	}
	return (length + 1); 
}

char *ft_itoa(int n)
{
	char *result;
	int index;

	index = ft_arrlen(n);
	result = (char *)malloc(sizeof(char) * index);
	if (result == NULL)
		return (NULL);
	result[--index] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while(n / 10 > 0 || n % 10 > 0)
	{
		result[--index] = n % 10 + '0';
		n = n / 10;
	}
	return (result);
}
