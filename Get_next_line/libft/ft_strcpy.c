/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:54:54 by bold-hen          #+#    #+#             */
/*   Updated: 2018/11/21 17:28:03 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(src);
	while (i <= len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
