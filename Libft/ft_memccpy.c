/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:42:27 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 15:39:01 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (dst == src)
		return (dst);
	while(n > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		if ((unsigned char)c == *(unsigned char *)src)
			break;
		src++;
		n--;
	}
	if (n > 0)
		return ((unsigned char *)dst);
	else
		return (NULL);
}
