/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bold-hen <bold-hen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:03:01 by bold-hen          #+#    #+#             */
/*   Updated: 2019/01/25 13:33:24 by bold-hen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	tail_exist(t_list *tails, int fd, char **buf)
{
	if (tails == NULL)
		return (0);
	while (tails != NULL)
	{
		if ((tails)->content_size == (size_t)fd)
		{
			ft_memcpy(*buf, (tails)->content, ft_strlen((tails)->content));
			return (1);
		}
		(tails) = (tails)->next;
	}
	return (0);
}

static int	add_tail(t_list **tails, int fd, char *content)
{
	t_list *tail;

	tail = ft_lstnew(NULL, 0);
	if (tail == NULL)
		return (0);
	tail->content_size = (size_t)fd;
	tail->content = (char *)malloc(sizeof(char) * ft_strlen(content));
	if (tail->content == NULL)
	{
		free(tail);
		return (0);
	}
	content++;
	ft_memmove(tail->content, content, ft_strlen(content) + 1);
	if (*tails == NULL)
		*tails = tail;
	else
		ft_lstadd(tails, tail);
	tail = NULL;
	free(tail);
	return (1);
}

static int	remove_tail(t_list **tails, int fd)
{
	t_list *tail;

	if ((*tails)->content_size == (size_t)fd)
	{
		tail = *tails;
		*tails = (*tails)->next;
		free(tail->content);
		free(tail);
		return (1);
	}
	while ((*tails)->next != NULL)
	{
		if ((*tails)->next->content_size == (size_t)fd)
		{
			tail = (*tails)->next;
			(*tails)->next = (*tails)->next->next;
			free(tail->content);
			free(tail);
			return (1);
		}
		tails = &(*tails)->next;
	}
	return (0);
}

static int	read_line(t_list **tails, int fd, char **str, char *buf)
{
	long	rd;
	char	*str1;

	while (!strchr(buf, '\n'))
	{
		str1 = *str;
		*str = ft_strjoin(*str, buf);
		free(str1);
		rd = read(fd, buf, BUFF_SIZE);
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		if (rd == 0 && !**str)
			return (0);
		else if (rd == 0)
			return (1);
	}
	if (!add_tail(tails, fd, ft_strchr(buf, '\n')))
		return (-1);
	buf[ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n'))] = '\0';
	str1 = *str;
	*str = ft_strcat(ft_strcat(ft_strnew(ft_strlen(*str) + ft_strlen(buf) + 1)
				, str1), buf);
	free(str1);
	return (1);
}

int			get_next_line(const int fd, char **str)
{
	static t_list	*tails;
	char			*buf;
	int				read_result;

	if (fd < 0)
		return (-1);
	if (str == NULL)
		return (-1);
	*str = ft_strnew(1);
	buf = ft_strnew(BUFF_SIZE + 1);
	if (buf == NULL)
		return (-1);
	if (tail_exist(tails, fd, &buf))
	{
		if (remove_tail(&tails, fd) == 0)
		{
			free(buf);
			return (-1);
		}
	}
	read_result = read_line(&tails, fd, str, buf);
	free(buf);
	return (read_result);
}
