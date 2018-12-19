/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:35:15 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/12 11:33:00 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	if(ft_strlen(dst) > size - 1)
		return (ft_strlen(dst) + size - 2);
	else 
		size = size - ft_strlen(dst);
	while(*dst)
		dst++;
	while(size > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
