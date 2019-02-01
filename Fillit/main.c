#include "Fillit.h"

t_point *start_point()
{
    t_point *result;

    result = (t_point *)malloc(sizeof(t_point));
    if (result == NULL)
        return (NULL);
    result->x = 0;
    result->y = 0;
    return (result);
}

t_point *find_position(char **field, t_list *tetremin, t_point *point)//возвращает следующую точку после той куда смогли поставить
{
    while (field)
    {

        (*field)++;
    }

    return (0);
}

int initialize_field(char ***field)
{
    int i;
    int j;

    i = 0;
    *field = (char **)malloc(sizeof(char *) * 3);
    if (*field == NULL)
        return (0);
    (*field)[2] = NULL;
    while ((*field)[i])
    {
        (*field)[i] = ft_strnew(3);
        if ((*field)[i] == NULL)
            return (0);
        j = 0;
        while (j < 3)
        {
            (*field)[i][j] = '.';
            j++;
        }
        i++;
    }
    return (1);
}

void free_field(char **field)
{
    while (*field)
    {
        free(*field);
        field++;
    }
    free(field);
}

int rebuild_field(char ***field)
{
    size_t i;
    size_t j;

    i = 0;
    while ((*field)[i])
        i++;
    j = i;
    free_field(*field);
    *field = (char **)malloc(sizeof(char *) * (i + 2));
    if (*field == NULL)
        return (0);
    (*field)[i + 1] = NULL;
    while (i >= 0)
    {
        (*field)[i] = ft_strnew(i + 2);
        if ((*field)[i] == NULL)
            return (0);
        while (j >= 0)
        {
            (*field)[i][j] = '.';
            j--;
        }
        j = ft_strlen((*field)[i]) - 1;
        i--;
    }
    return (1);
}

int solve(t_list **args, char ***field, t_point *point)
{
    int result;

    if (args == NULL)
        return (1);
    result = 0;
    while (result == 0)
    {
        point = find_position(*field, *args, point);
        if (point == NULL)
        {
            if (rebuild_field(field))
                return (solve(args, field, start_point()));
            return -1;
        }
        result = solve(args, field, point);
    }
    if (result == 1)
        return (1);
    else
        return (-1);
}

int validate_buf(char *buf)
{
    int count;

    count = 0;
    if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
        return (0);
    while (*buf)
    {
        if (*buf != '\n' && *buf != '.' && *buf != '#')
            return (0);
        if (*buf == '#')
            count++;
        buf++;
    }
    if (count == 4)
        return (1);
    return (0);
}

void initialize_figure(t_figure *figure)
{
    int x;

    x = 0;
    while (x < 4)
    {
        figure->x[x] = -1;
        figure->y[x] = -1;
        x++;
    }
}

void add_coordinates(int x, int y, t_figure *figure)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (figure->x[i] != -1)
        {
            figure->x[i] = x;
            figure->y[i] = y;
        }
        i++;
    }
}

int add_point(t_list *figure, int x, int y, char check)
{
    t_figure *mas;

    if (check == '#')
    {
        if (figure->content_size == 0)
        {
            mas = (t_figure *)malloc(sizeof(t_figure));
            if (mas == NULL)
                return (0);
            figure->content_size = 1;
            initialize_figure(mas);
            figure->content = mas;
        }
        add_coordinates(x, y, (t_figure *)figure->content);
    }
    return (1);
}

t_list *create_figure(char *buf)
{
    t_list *figure;
    char **map;
    int x;
    int y;

    y = 0;
    figure = ft_lstnew(NULL, 0);
    if (figure == NULL)
        return (0);
    map = ft_strsplit(buf, '\n');
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x])
        {
            if (!add_point(figure, x, y, map[y][x]))
                return (0);
            x++;
        }
        y++;
    }
    free_field(map);
    return (figure);
}

int add_figure(char *buf, t_list **args)
{
    if (*args == NULL)
    {
        *args = create_figure(buf);
        if ((*args)->next == NULL)
            return (0);
        (*args)->content_size = 'A';
        return (1);
    }
    while ((*args)->next != NULL)
        *args = (*args)->next;
    (*args)->next = create_figure(buf);
    if ((*args)->next == NULL)
        return (0);
    (*args)->next->content_size = (*args)->content_size + 1;
    return (1);
}

int validate_input(char *buf, t_list **args)
{
    int count;

    count = 0;
    buf[20] = '\0';
    if (!validate_buf(buf))
        return (0);
    while (*buf)
    {
        if (*buf == '#' && buf[1] == '#')
            count++;
        if (ft_strlen(buf) >= 5)
        {
            if (buf[5] == '#' && *buf == '#')
                count++;
        }
        buf++;
    }
    if (count == 3 || count == 4)
        return (add_figure(buf - 20, args));
    return (0);
}

int put_error(t_list **args_free, char *to_free, int to_close)
{
    ft_putstr("error\n");
    if (args_free != NULL)
        ft_lstdel(args_free, NULL);
    if (to_free != NULL)
        free(to_free);
    if (to_close != 0)
        close(to_close);
    return (0);
}

int read_input(char *file_path, t_list **args)
{
    char *buf;
    int fd;
    long rd;

    buf = ft_strnew(BUFF_SIZE + 1);
    if (buf == NULL)
        return (put_error(NULL, NULL, 0));
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return (put_error(NULL, buf, 0));
    while (1)
    {
        rd = read(fd, buf, BUFF_SIZE);
        if (rd == 0 && (*args)->content_size == 0)
        {
            free(buf);
            return (1);
        }
        if (rd < 20)
            return (put_error(args, buf, fd));
        buf[rd] = '\0';
        if (!validate_input(buf, args))
            return (put_error(args, buf, fd));
    }
}

void print_result(char **field)
{
    int i;

    i = 0;
    while (field[i])
    {
        ft_putstr(field[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_list **args;
    char **field;

    args = (t_list **)malloc(sizeof(t_list *));
    if (args == NULL)
        return (put_error(NULL, NULL, 0));
    if (argc == 2)
    {
        if (read_input(argv[1], args))
        {
            if (initialize_field(&field) == 0)
                return (put_error(args, NULL, 0));
            if (solve(args, &field, start_point()))
                print_result(field);
            else
            {
                free_field(field);
                return (put_error(args, NULL, 0));
            }
        }
        return (0);
    }
    else
        return (put_error(NULL, NULL, 0));
}