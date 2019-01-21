/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:54:30 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/17 12:18:52 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *string;

	string = (char *)malloc(sizeof(char) * (size + 1));
	if (string != NULL)
		ft_bzero(string, size + 1);
	return (string);
}
