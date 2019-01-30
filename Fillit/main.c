#include "Fillit.h"

void tetremin_representation(int *figure, char tetrimin)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (tetrimin == 'B')
    }
}

int find_position(char **field, char tetremin, int number)//поиск позиции для текущей фигуры на текущем поле
{
    int figure[4];

    tetremin_representation(figure, tetremin);
    while (*field)
    {

        (*field)++;
    }

    return (0);
}

int initiate_field(char ***field, char *args)// +
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

void free_field(char **field)// +
{
    while (*field)
    {
        free(*field);
        field++;
    }
    free(field);
}

int rebuild_field(char ***field)// +
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

int solve(char *args, char **field, int number)//args - список полученных фигурок в порядке получения из файла, конец полученных фигурок '\0'. Возвращаемые значения: 1 - решение найдено 0 - изменить размеры поля
{
    if (args[number] == '\0')
        return (1);
    if (find_position(field, args[number], number))
    {
        if (!solve(args, field, number + 1))
        {
            rebuild_field(&field);
            return (solve(args, field, 0));
        }
        else
            return (1);
    }
    else
        return (0);
}

int count_chr(char *str, char to_count)
{
    int result;
    int i;

    i = 0;
    result = 0;
    while (i < 4)
    {
        if (str[i] == to_count)
            result++;
        else if (str[i] != '.' && str[i] != '#')
            return (-1);
        i++;
    }
    return (result);
}

int chr_position(char *buf, char to_find, int count)
{
    int i;

    i = 1;
    while (i < 5)
    {
        if (buf[i - 1] == to_find)
            break ;
        i++;
    }
    if (count == 1)
        return (i);
    if (count == 2 && buf[i] == to_find)
        return (i);
    if (count == 3 && buf[i] == to_find && buf[i + 1] == to_find)
        return (i);
    return (-1);
}

int validate_str(char *buf)
{
    if (count_chr(buf, '#') == 0)
        return (0);
    if (count_chr(buf, '#') == 4)
        return (10);
    if (count_chr(buf, '#') == 1)
        return (chr_position(buf, '#', 1));
    if (count_chr(buf, '#') == 2)
        return (chr_position(buf, '#', 2) + 4);
    if (count_chr(buf, '#') == 3)
        return (chr_position(buf, '#', 3) + 7);
}

char *ft_strrealloc(char *str, size_t size) // +
{
    char *result;

    result = (char *)malloc(sizeof(char) * size);
    if (result == NULL)
        return (NULL);
    result = ft_memmove(result, str, size);
    free(str);
    return (result);
}

char validate_mas(int *to_validate)
{

}

int validate_input(char *buf, char **args)//через ft_strrealloc меняем ссылку на новый список фигур;
{
    int to_check[4];
    int i;

    i = 0;
    buf[20] = '\0';
    while (*buf)
    {
        if (buf[4] != '\n')
            return (0);
        if (count_chr(buf, '.') + count_chr(buf, '#') != 4)
            return (0);
        to_check[i] = validate_str(buf);
        i++;
    }
    if (validate_mas(to_check))
    {
        *args = ft_strrealloc(*args, ft_strlen(*args) + 2);
        (*args)[ft_strlen(*args)] = validate_mas(to_check);
        return (1);
    }
    return (0);
}

int put_error(char **args_free, char *to_free, int to_close)// +
{
    ft_putstr("error\n");
    if (args_free != NULL)
        free(args_free);
    if (to_free != NULL)
        free(to_free);
    if (to_close != 0)
        close(to_close);
    return (0);
}

int read_input(char *file_path, char **args)// +
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
        if (rd == 0 && !**args)
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

void print_result(char **field)// +
{
    int i;

    i = 0;
    while (field[i])
    {
        ft_putstr(field[i]);
        i++;
    }
}

int main(int argc, char **argv)// +
{
    char *args;
    char **field;

    args = (char *)malloc(sizeof(char));
    if (args == NULL)
        return (put_error(NULL, NULL, 0));
    if (argc == 2)
    {
        args = ft_strnew(1);
        if (args == NULL)
            return (put_error(NULL, NULL, 0));
        if (read_input(argv[1], &args))
        {
            if (initiate_field(&field, args) == 0)
                return (put_error(&args, NULL, 0));
            solve(args, field, 0);
            print_result(field);
            return (0);
        }
        else
            return (0);
    }
    else
        return (put_error(NULL, NULL, 0));
}