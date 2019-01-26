/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:11:37 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 11:40:31 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*result;

	result = (char *)haystack;
	while (*result && len > 0)
	{
		i = 0;
		while (result[i] == needle[i] && result[i] && i < len)
		{
			if (needle[i + 1] == '\0')
				return (result);
			i++;
		}
		if (needle[i] == '\0')
			return (result);
		len--;
		result++;
	}
	return (NULL);
}
