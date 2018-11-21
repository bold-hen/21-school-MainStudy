/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:07:10 by bold-hen          #+#    #+#             */
/*   Updated: 2018/08/31 15:44:57 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_string_length(char *str)
{
	unsigned int length;

	length = 1;
	while (*str++)
		length++;
	return (length);
}

char			*ft_strdup(char *src)
{
	char			*str;
	unsigned int	length;

	length = ft_string_length(src);
	str = (char *)malloc(sizeof(char) * length);
	while (length > 0)
	{
		length--;
		str[length] = src[length];
	}
	return (str);
}
