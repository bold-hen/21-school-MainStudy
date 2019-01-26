/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:26:36 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 11:57:14 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *final;
	t_list *result;
	t_list *temp;

	temp = lst;
	final = (t_list *)malloc(sizeof(t_list));
	result = (t_list *)malloc(sizeof(t_list));
	final->next = result;
	while (temp)
	{
		if (f)
		{
			result->next = f(temp);
			result = result->next;
		}
		temp = temp->next;
	}
	return (final->next->next);
}
