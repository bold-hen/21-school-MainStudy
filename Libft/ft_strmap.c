/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:09:57 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 12:15:21 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char *result;
	size_t index;

	index = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while(*s)
	{
		result[index] = f(*s);
		index++;
		s++;
	}
	result[index] = '\0';
	return (result);
}
