/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:11:37 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/17 10:48:59 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;

    while(*haystack && len > 0)
    {
        i = 0;
        while(haystack[i] == needle[i] && haystack[i] && i < len)
        {
            if(needle[i + 1] == '\0')
                return haystack;
            i++;
        }
		if(needle[i] =='\0')
            return haystack;
		len--;
        haystack++;
    }
    return (NULL);
}
