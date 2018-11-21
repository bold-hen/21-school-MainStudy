/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:54:08 by bold-hen          #+#    #+#             */
/*   Updated: 2018/08/31 16:50:07 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*to_return;
	unsigned int	length;

	length = max - min;
	to_return = 0x0;
	if (max > min)
	{
		to_return = (int *)malloc(sizeof(*to_return) * length);
		if (to_return == 0x0)
			return (to_return);
		while (max > min)
		{
			to_return[--length] = --max;
		}
	}
	return (to_return);
}
