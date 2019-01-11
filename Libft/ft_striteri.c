/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:05:35 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/19 10:09:07 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	index = 0;
	while(*s)
	{
		*f(index, s);
		index++;
		s++;
	}
}
