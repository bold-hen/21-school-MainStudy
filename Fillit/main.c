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

void clear_previous_position(char tetrimin, char **field)
{
    int x;
    int y;

    y = 0;
    while(field[y] != NULL)
    {
        x = 0;
        while (field[y][x])
        {
            if (field[y][x] == tetrimin)
                field[y][x] = '.';
            x++;
        }
        y++;
    }
}

int try_insert(char ***field, t_list *tetrimin, t_point *check)
{
    int i;
    t_point *start;

    start = (t_point *)malloc(sizeof(t_point));
    if (start == NULL)
        return (0);
    start->x = check->x;
    start->y = check->y;
    i = 0;
    while (i < 4)
    {
        check->y = start->y + ((t_figure *)tetrimin->content)->y[i] - ((t_figure *)tetrimin->content)->y[0];
        check->x = start->x + ((t_figure *)tetrimin->content)->x[i] - ((t_figure *)tetrimin->content)->x[0];
        if (check->y < 0 || check->x < 0 || check->y == ft_strlen(**field) || check->x == ft_strlen(**field))
            return (0);
        if ((*field)[check->y][check->x] != '.')
            return (0);
        (*field)[check->y][check->x] = ((char)tetrimin->content_size);
        i++;
    }
    return (1);
}

void get_next_point(char **field, t_point **previous)
{
    if (field[(*previous)->x + 1] == '\0')
    {
        (*previous)->x = 0;
        if (field[(*previous)->y + 1] == NULL)
            *previous = NULL;
        else
            (*previous)->y = (*previous)->y + 1;
    }
    else
        (*previous)->x = (*previous)->x + 1;
}

int find_position(char ***field, t_list *tetremin, t_point **point)//возвращает следующую точку после той куда смогли поставить
{
    clear_previous_position((char)tetremin->content_size, *field);
    while ((*field)[(*point)->y] != NULL)
    {
        while ((*field)[(*point)->y][(*point)->x])
        {
            if (try_insert(field, tetremin, *point))
            {
                get_next_point(*field, point);
                return (1);
            }
            clear_previous_position((char)tetremin->content_size, *field);
            (*point)->x++;
        }
        (*point)->x = 0;
        (*point)->y++;
    }
    *point = NULL;
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
        while (j < 2)
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
    char *to_free;

    while (*field)
    {
        to_free = *field;
        field++;
        free(to_free);
    }
    free(*field);
}

char *strrealloc(char *str, size_t size)
{
    char *result;

    result = ft_strnew(size);
    if (result == NULL)
        return (NULL);
    result = ft_strcat(result, str);
    free(str);
    return (result);
}

int copy_field(char ***field, char ***dst, int length)
{
    int count;

    count = 0;
    while (count < length - 2)
    {
        (*dst)[count] = ft_strnew((size_t)length);
        if ((*dst)[count] == NULL)
            return (0);
        (*dst)[count] = ft_strcat((*dst)[count], (*field)[count]);
        (*dst)[count][length - 2] = '.';
        count++;
    }
    (*dst)[count] = ft_strnew((size_t)length);
    while (length >= 2)
    {
        (*dst)[count][length - 2] = '.';
        length--;
    }
    return (1);
}

int rebuild_field(char ***field)
{
    int i;
    char **result;

    i = 0;
    while ((*field)[i] != NULL)
        i++;
    result = (char **)malloc(sizeof(char *) * (i + 2));
    if (result == NULL)
        return (0);
    result[i + 1] = NULL;
    if (!copy_field(field, &result, i + 2))
        return (0);
    free_field(*field);
    *field = result;
    return (1);
}

int solve(t_list *args, char ***field, t_point *point)
{
    int result;

    if (args == NULL)
        return (1);
    result = 0;
    while (result == 0)
    {
        find_position(field, args, &point);
        if (point == NULL)
        {
            if (!rebuild_field(field))
                return (-1);
            return (solve(args, field, start_point()));
        }
        else
            result = solve(args->next, field, point);
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
        if (figure->x[i] == -1)
        {
            figure->x[i] = x;
            figure->y[i] = y;
            break;
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
        if (*args == NULL)
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
        if (rd == 0 && (*args)->content_size != 0)
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
        ft_putchar('\n');
        i++;
    }
}

int main(int argc, char **argv)
{
    t_list *args;
    char **field;

    //args = (t_list *)malloc(sizeof(t_list));
    //if (args == NULL)
     //   return (put_error(NULL, NULL, 0));
    //if (argc == 2)
    {
        if (read_input("/Users/bold-hen/MyGit/Fillit/tests/test_4.txt", &args))
        {
            if (initialize_field(&field) == 0)
                return (put_error(&args, NULL, 0));
            if (solve(args, &field, start_point()))
                print_result(field);
            else
            {
                free_field(field);
                return (put_error(&args, NULL, 0));
            }
        }
        return (0);
    }
    //else
        //return (put_error(NULL, NULL, 0));
}