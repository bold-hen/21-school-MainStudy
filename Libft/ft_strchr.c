/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:38:44 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 12:12:07 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char *result;

	result = (char *)s;
	while(*result)
	{
		if(*result == (char)c)
			return (result);
		result++;
	}
	if(*result == (char)c)
		return (result);
	return (NULL);
}
