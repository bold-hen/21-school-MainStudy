/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:45:06 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 17:07:03 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if(!*haystack && !*needle)
        return ((char *)haystack);
	while(*haystack)
	{
		i = 0;
		while(haystack[i] == needle[i] && haystack[i])
		{
			if(needle[i + 1] == '\0')
				return ((char *)haystack);
			i++;
		}
		if(needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
