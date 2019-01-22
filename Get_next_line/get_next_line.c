#include "get_next_line.h"

t_list *findlist(t_list *lst, int fd)
{
    if (lst == NULL)
        return (NULL);
    while (lst->content_size != (size_t)fd)
    {
        if (lst->next != NULL)
            lst = lst->next;
        else
            break;
    }
    if (lst->content_size == (size_t)fd)
        return (lst);
    else
        return (NULL);
}

void dellist(t_list *lst, int fd)
{
    t_list *temp;

    temp = (t_list *)malloc(sizeof(t_list));
    while (lst->content_size != (size_t)fd)
    {
        temp = lst;
        lst = lst->next;
    }
    if (temp != NULL)
    {
        temp->next = lst->next;
        ft_lstdelone(&lst, NULL);
    }
    else
        {
            temp = lst->next;
            ft_lstdelone(&lst, NULL);
            lst = temp;
        }
    temp = NULL;
    free(temp);
}

t_list *newlist(char *content, int fd)
{
    t_list *nlst;

    nlst = (t_list *) malloc(sizeof(t_list));
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
    nlst->content_size = (size_t) fd;
    nlst->next = NULL;
    content = NULL;
    free(content);
    return (nlst);
}

int get_next_line(const int fd, char **line)
{
    static t_list *endings;
    char *buf;
    long readed;

    *line = ft_strnew(1);
    buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
    if (buf == NULL)
        return (-1);
    if(findlist(endings, fd) != NULL)
    {
        buf = (char *)findlist(endings, fd)->content;
        readed = ft_strlen(buf);
        dellist(endings, fd);
    }
    else
    {
        readed = read(fd, buf, BUFF_SIZE);
        buf[BUFF_SIZE] = '\0';
    }
    while (!ft_strchr(buf, (char)26) && !ft_strchr(buf, '\n'))
    {
        buf[BUFF_SIZE] = '\0';
        *line = ft_strjoin(*line, buf);
        readed = read(fd, buf, BUFF_SIZE);
        if(readed == 0)
            return (0);
        if (readed == -1)
            return (-1);
    }
    if ((ft_strchr(buf, '\n') || readed != BUFF_SIZE) && !ft_strchr(buf, (char)26))
    {
        ft_lstadd(&endings, newlist(ft_strchr(buf, '\n'), fd));
        if (buf[0] != '\n')
            *line = ft_strjoin(*line, ft_strsplit(buf, '\n')[0]);
        else
            *line = ft_strjoin(*line, "");
        return (1);
    }
    else
    {
        ft_strjoin(*line, ft_strsplit(buf, (char)26)[0]);
        return (0);
    }
}