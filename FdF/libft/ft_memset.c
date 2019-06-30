/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:46:53 by bold-hen          #+#    #+#             */
/*   Updated: 2018/11/24 14:16:51 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	while (len > 0)
		((unsigned char *)d)[--len] = (unsigned char)c;
	return (d);
}
