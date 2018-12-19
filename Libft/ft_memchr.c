/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:01:39 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/11 09:11:05 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			break;
		s++;
		n--;
	}
	if (n > 0)
		return (s);
	return (NULL);
}
