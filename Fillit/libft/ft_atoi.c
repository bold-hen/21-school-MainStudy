/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:45:48 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 12:09:15 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v') || (*str == '\r')
			|| (*str == '\f') || (*str == '\n'))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (number * 10 / 10 != number || number * 10 + (*str - 48) < 0)
			return ((sign > 0) ? -1 : 0);
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * sign);
}
