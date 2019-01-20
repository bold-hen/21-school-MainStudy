/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:43:24 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/19 10:49:23 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *result;
	size_t index;

	if(s == NULL)
		return (NULL);
	index = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while(len > 0)
	{
		result[index] = s[start];
		start++;
		index++;
		len--;
	}
	result[index] = '\0';
	return (result);
}
