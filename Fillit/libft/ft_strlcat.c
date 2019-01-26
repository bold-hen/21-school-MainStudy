/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:35:15 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 11:46:03 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t result;

	result = ft_strlen((char *)src);
	(ft_strlen(dst) > size) ? (result += size) : (result += ft_strlen(dst));
	if (size == 0)
		return (result);
	if (ft_strlen(dst) > size - 1)
		return (result);
	else
		size = size - ft_strlen(dst);
	while (*dst)
		dst++;
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (result);
}
