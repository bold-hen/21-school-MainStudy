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
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (l == NULL)
        return (NULL);
	if (content == NULL)
    {
        l->content_size = 0;
        l->content = NULL;
    }
	else
	{
		l->content = malloc(sizeof(content_size));
		if(l->content == NULL)
            return (NULL);
        ft_memcpy(l->content, content, content_size);
        l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}
