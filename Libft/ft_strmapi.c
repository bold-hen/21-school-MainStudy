/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:20:58 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/19 10:26:39 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *result;
	unsigned int index;

	index = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while(*s)
	{
		result[index] = *f(index, *s);
		index++;
		s++;
	}
	result[index] = '\0';
	return (result);
}
