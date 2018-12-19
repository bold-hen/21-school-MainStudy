/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:47:03 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/12 11:56:42 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t len;
	
	len = ft_strlen(s);
	while(ft_strlen(s) > 0)
		s++;
	while(len >= 0)
	{
		if(*s = (char)c)
			return (s);
		s--;
		len--;
	}
	return (NULL);
}
