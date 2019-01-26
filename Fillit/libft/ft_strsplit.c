/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:08:18 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 12:17:27 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrcount(char const *s, char c)
{
	size_t	index;
	size_t	count;
	char	previous;

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

static size_t	ft_wln(char *s, char c)
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

static void		split(char const *s, char c, char **result)
{
	int		i;
	size_t	j;

	i = -1;
	while (*s)
	{
		j = 0;
		if (*s != c)
			result[++i] = (char *)malloc(sizeof(char) * ft_wln((char *)s, c));
		while (*s != c && *s)
			result[i][j++] = *s++;
		if (i >= 0 && j != 0)
			result[i][j] = '\0';
		if (*s)
			s++;
	}
	result[i + 1] = (void *)0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ft_substrcount(s, c));
	if (result == NULL)
		return (NULL);
	split(s, c, result);
	return (result);
}
