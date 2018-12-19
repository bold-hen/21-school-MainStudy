/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:39:41 by bold-hen          #+#    #+#             */
/*   Updated: 2018/12/17 15:48:37 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	void *result;

	result = (void *)malloc(size_of(void) * size);
	ft_bzero(result, size);
	return (result);
}
