/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:08:18 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 12:32:01 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_substrcount(char *s, char c)
{
	size_t index;
	size_t count;
	char previous;

	previous = c;
	count = 0;
	index = 0;
	while (s[index])
	{
		if (previous == c && s[index] != c)
			count++;
		previous = s[index];
		index++;
	}
	return (count + 1);
}

static size_t ft_wordlen(char *s, char c)
{
	size_t length;

	length = 0;
	while (*s != c && *s)
	{
		length++;
		s++;
	}
	return (length + 1);
}

char **ft_strsplit(char const *s, char c)
{
	char **result;
	int i;
	int j;
	char previous;

	previous = c;
	i = -1;
	result = (char **)malloc(sizeof(char *) * ft_substrcount((char *)s, c));
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		j = 0;
		if (previous == c && *s != c)
		{
			i++;
			result[i] = (char *)malloc(sizeof(char) * ft_wordlen((char *)s, c));
		}
		while (*s != c && *s)
			result[i][j++] = *s++;
		if (i >= 0 && j != 0)
			result[i][j] = '\0';
		s++;
	}
	result[i + 1] = (char *)malloc(sizeof(char));
	result[i + 1][0] = '\0';
	return (result);
}
