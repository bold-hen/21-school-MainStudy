/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:51:36 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/15 16:43:54 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	newlist->content = (void *)malloc(content_size);
	ft_memcpy(newlist->content, content, content_size);	
	newlist->content_size = content_size;
	newlist->next = (t_list *)malloc(sizeof(t_list));
	newlist->next = NULL;
	return (newlist);
}
