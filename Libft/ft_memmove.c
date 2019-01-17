/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:56:14 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 16:08:48 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	size_t step;

	(src > dst) ? (i = 0) : (i = len - 1);
	(src > dst) ? (step = 1) : (step = -1);
	if (len == 0 || dst == src)
		return (dst);
	while (len > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i += step;
		len--;
	}
	return (dst);
}
