/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:56:14 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 11:54:13 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	size_t step;

	if (src > dst)
	{
		i = 0;
		step = 1;
	}
	else
	{
		i = len - 1;
		step = -1;
	}
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
