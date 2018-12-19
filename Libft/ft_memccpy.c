/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:42:27 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/11 08:55:36 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while(n > 0)
	{
		*dst = *src;
		dst++;
		if ((unsigned char)c == (unsigned char)*src)
			break;
		src++;
		n--;
	}
	if (n > 0)
		return (dst);
	else
		return (NULL);
}
