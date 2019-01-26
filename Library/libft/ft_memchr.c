/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:01:39 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 11:55:35 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *result;

	result = (unsigned char *)s;
	while (n > 0)
	{
		if (*result == (unsigned char)c)
			break ;
		result++;
		n--;
	}
	if (n > 0)
		return (result);
	return (NULL);
}
