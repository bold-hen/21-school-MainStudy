/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:47:03 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 12:27:21 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t len;
	char *result;

	result = (char *)s;
	len = ft_strlen(result) + 1;
	while(ft_strlen(result) > 0)
		result++;
	while(len != 0)
	{
		if(*result == (char)c)
			return (result);
		result--;
		len--;
	}
	return (NULL);
}
