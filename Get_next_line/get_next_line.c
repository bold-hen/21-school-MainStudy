#include "get_next_line.h"

static t_list *tail_exist(t_list *tails, int fd)
{
    t_list *tail;

    if (tails == NULL)
        return (NULL);
    tail = tails;
    while (tail != NULL)
    {
        if (tail->content_size == (size_t)fd)
            return (tail);
        tail = tail->next;
    }
    return (NULL);
}

static int add_tail(t_list **tails, int fd, char *content)
{
    t_list *tail;

    tail = (t_list *)malloc(sizeof(t_list));
    if (tail == NULL)
        return (0);
    tail = ft_lstnew(NULL, 0);
    if (tail == NULL)
        return (0);
    tail->content_size = (size_t)fd;
    tail->content = (char *)malloc(sizeof(char) * (ft_strlen(content) + 1));
    if (tail->content == NULL)
        return (0);
    else
    {
        content++;
        ft_memcpy(tail->content, content, (ft_strlen(content) + 1));
    }
    if (*tails == NULL)
        *tails = tail;
    else
        ft_lstadd(tails, tail);
    return (1);
}

static int remove_tail(t_list **tails, int fd)
{
    t_list *tail;

    tail = (t_list *)malloc(sizeof(t_list));
    if (tail == NULL)
        return (0);
    if ((*tails)->content_size == (size_t)fd)
    {
        tail = *tails;
        *tails = (*tails)->next;
        free(tail);
        return (1);
    }
    while ((*tails)->next != NULL)
    {
        if ((*tails)->next->content_size == (size_t)fd)
        {
            tail = (*tails)->next;
            (*tails)->next = (*tails)->next->next;
            free(tail);
            return (1);
        }
        tails = &(*tails)->next;
    }
    free (tail);
    return (0);
}

static int read_line(t_list **tails, int fd, char **str, char *buf)
{
    long rd;
    char *todel;

    while (!strchr(buf, '\n'))
    {
        todel = *str;
        *str = ft_strjoin(*str, buf);
        free(todel);
        rd = read(fd, buf, BUFF_SIZE);
        if (rd == -1)
            return (-1);
        else
            buf[rd] = '\0';
        if (rd == 0 && !**str)
            return (0);
        else if (rd == 0)
            return (1);
    }
    if (!add_tail(tails, fd, ft_strchr(buf, '\n')))
        return (-1);
    todel = *str;
    if (buf[0] != '\n')
        *str = ft_strjoin(*str, ft_strsplit(buf, '\n')[0]);
    else
        *str = ft_strjoin(*str, "");
    free(todel);
    return (1);
}

int get_next_line(const int fd, char **str)
{
    static t_list *tails;
    char *buf;
    int read_result;

    if (fd < 0)
        return (-1);
    buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
    if (buf == NULL)
        return (-1);
    buf[0] = '\0';
    if (str == NULL)
    {
        free(buf);
        return (-1);
    }
    *str = ft_strnew(1);
    if (tail_exist(tails, fd))
    {
        buf = tail_exist(tails, fd)->content;
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