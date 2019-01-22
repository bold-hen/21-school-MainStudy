/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:52:43 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/22 15:17:40 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*findlist(t_list *lst, int fd)
{
	if (lst == NULL)
		return (NULL);
	while (lst->content_size != (size_t)fd)
	{
		if (lst->next != NULL)
			lst = lst->next;
		else
			break ;
	}
	if (lst->content_size == (size_t)fd)
		return (lst);
	else
		return (NULL);
}

void	dellist(t_list *lst, int fd)
{
	t_list *previous;
	t_list *find;

	find = lst;
	previous = NULL;
	while (find->content_size != (size_t)fd && find->next != NULL)
	{
		previous = find;
		find = lst->next;
	}
	if (find->content_size == (size_t)fd)
	{
		if (previous != NULL)
			previous->next = find->next;
		ft_lstdelone(&find, NULL);
	}
	free(find);
	free(previous);
}

t_list	*newlist(char *content, int fd)
{
	t_list *nlst;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	nlst->content = malloc(sizeof(char) * (ft_strlen(content) + 1));
	if (nlst->content == NULL)
		return (NULL);
	if (content[0] == '\n')
	{
		content++;
		ft_memcpy(nlst->content, content, (ft_strlen(content) + 1));
	}
	else
		ft_memcpy(nlst->content, content, (ft_strlen(content) + 1));
	nlst->content_size = (size_t)fd;
	nlst->next = NULL;
	content = NULL;
	free(content);
	return (nlst);
}

int		readline(char *buf, char **line, int fd, t_list **endings)
{
	long rd;

	rd = ft_strlen(buf);
	while (!ft_strchr(buf, '\n') && rd != 0)
	{
		*line = ft_strjoin(*line, buf);
		rd = read(fd, buf, BUFF_SIZE);
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
	}
	if (rd != 0)
	{
		ft_lstadd(endings, newlist(ft_strchr(buf, '\n'), fd));
		if (buf[0] != '\n')
			*line = ft_strjoin(*line, ft_strsplit(buf, '\n')[0]);
		else
			*line = ft_strjoin(*line, "");
		free(buf);
		return (1);
	}
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*endings;
	char			*buf;
	long			rd;

	if (fd < 0)
		return (-1);
	*line = ft_strnew(1);
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buf == NULL)
		return (-1);
	if (findlist(endings, fd) != NULL)
	{
		buf = (char *)findlist(endings, fd)->content;
		rd = ft_strlen(buf);
		buf[rd] = '\0';
		dellist(endings, fd);
	}
	else
	{
		rd = read(fd, buf, BUFF_SIZE);
		buf[rd] = '\0';
	}
	return (readline(buf, line, fd, &endings));
}
