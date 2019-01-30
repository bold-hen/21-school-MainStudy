#include "Fillit.h"

int find_position(char **field, char tetremin, int number)//поиск позиции для текущей фигуры на текущем поле
{


    return (0);
}

int initiate_field(char ***field, char *args)// +
{
    int i;

    i = 0;
    *field = (char **)malloc(sizeof(char *) * (ft_strlen(args) + 1));
    if (*field == NULL)
        return (0);
    (*field)[ft_strlen(args)] = NULL;
    while ((*field)[i])
    {
        (*field)[i] = (char *)malloc(sizeof(char) * 11);
        if ((*field)[i] == NULL)
            return (0);
        i++;
    }
    return (1);
}

int rebuild_field(char ***field)
{

}

int solve(char *args, char **field, int number)//args - список полученных фигурок в порядке получения из файла, конец полученных фигурок '\0'. Возвращаемые значения: 1 - решение найдено 0 - изменить размеры поля
{
    if (args[number] == '\0')
        return (1);
    if (find_position(field, args[number], number))
    {
        while(!solve(args, field, number + 1))
            rebuild_field(&field);
        return (1);
    }

}

int validate_input(char *buf, char **args)//через ft_strrealloc меняем ссылку на новый список фигурок;
{

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