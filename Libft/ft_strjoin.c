/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:50:05 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/19 10:55:25 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	size_t index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (*s1)
	{
		result[index] = *s1;
		index++;
		s1++;
	}
	while (*s2)
	{
		result[index] = *s2;
		index++;
		s2++;
	}
	result[index] = '\0';
	return (result);
}
