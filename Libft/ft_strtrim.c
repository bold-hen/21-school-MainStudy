/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:55:32 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/19 11:07:12 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_substrlen(char const *s)
{
	size_t length;

    length = 0;
    while(*s == ' ' || *s == '\n' || *s == '\t')
        s++;
    if (!*s)
        return (1);
    while(*s)
    {
        length++;
        s++;
    }
	s--;
    while(*s == ' ' || *s == '\n' || *s == '\t')
    {
		s--;
        length--;
    }
    return (length);
}

char *ft_strtrim(char const *s)
{
	char *result;
	size_t length;
	size_t index;
	
	index = 0;
	length = ft_substrlen(s);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	while(*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while(length > 0)
	{
		result[index] = *s;
		index++;
		s++;
		length--;
	}
	result[index] = '\0';
	return (result);
}
