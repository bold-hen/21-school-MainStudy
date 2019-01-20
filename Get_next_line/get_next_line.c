#include "get_next_line.h"

size_t findindex(char *str)
{
    size_t length;

    length = 0;
    while (!ft_strchr(str, 3) && !ft_strchr(str, 10))
    {
        str++;
        length++;
    }
    return (length);
}

t_list *findlist(t_list *lst, int fd)
{
    t_list *flst;

    flst = (t_list *)malloc(sizeof(t_list));
    while (((t_line *)(lst->content))->fd != fd)
    {
        if (lst->next != NULL)
            lst = lst->next;
        else
            break;
    }
    if (((t_line *)(lst->content))->fd == fd)
        return (lst);
    else
        return (NULL);
}

void dellist(t_list *lst, int fd)
{
    t_list *temp;

    temp = (t_list *)malloc(sizeof(t_list));
    while (lst != NULL)
    {
        if (lst->content_size == fd)
            break;
        temp = lst;
        lst = lst->next;
    }
    if (lst != NULL)
    {
        if (temp != NULL)
        {
            temp->next = lst->next;
            ft_lstdelone(&lst, NULL);
        }
        else
            ft_lstdelone(&lst, NULL);
    }
}

t_line *newtail(char *str, int fd, size_t lise_size)
{
    t_line *tail;

    tail = (t_line *)malloc(sizeof(t_line));
    if (tail == NULL)
        return (NULL);
    tail->line = malloc(sizeof(char) * lise_size);
    if (tail->line == NULL)
        return (NULL);
    ft_memcpy(tail->line, str, lise_size);
    tail->fd = fd;
    return (tail);
}

int get_next_line(const int fd, char **line)
{
    static t_list *endings;
    char *buf;

    buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
    endings = ft_lstnew(newtail("\0", -1, 1), 0);
    if(!findlist(endings, fd))
    {
        ft_memcpy(*line, ((t_line *)findlist(endings, fd)->content)->line, findlist(endings, fd)->content_size);
        dellist(endings, fd);
    }
    read(fd, buf, BUFF_SIZE);
    while (!ft_strchr(buf, 3) && !ft_strchr(buf, 10))
    {
        ft_strjoin(*line, buf);
        read(fd, buf, BUFF_SIZE);
    }
    if (!ft_strchr(buf, 3))
    {
        ft_lstadd(&endings, ft_lstnew(newtail(&buf[findindex(buf)], fd, (BUFF_SIZE - findindex(buf))), (BUFF_SIZE - findindex(buf))));
        ft_strjoin(*line, ft_strsplit(buf, '\n')[0]);
    }
    else
    {
        ft_strjoin(*line, ft_strsplit(buf, (char)3)[0]);
    }
    return (1);
}