#include "Fillit.h"

int solve(char *args)//args - список полученных фигурок в порядке получения из файла, конец полученных фигурок '\0'
{

    return (1);
}

int validate_input(char *buf, char **args)//через ft_strrealloc меняем ссылку на новый список фигурок;
{

    return (1);
}

int put_error(char **args_free, char *to_free, int to_close)
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

int read_input(char *file_path, char **args)
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

char *ft_strrealloc(char *str, size_t size)
{
    char *result;

    result = (char *)malloc(sizeof(char) * size);
    if (result == NULL)
        return (NULL);
    result = ft_memmove(result, str, size);
    free(str);
    return (result);
}

int main(int argc, char **argv)
{
    char **args;

    args = (char **)malloc(sizeof(char *));
    if (args == NULL)
        return (put_error(NULL, NULL, 0));
    if (argc == 2)
    {
        *args = ft_strnew(1);
        if (*args == NULL)
            return (put_error(NULL, NULL, 0));
        if (read_input(argv[1], args))
            return (solve(*args));
        else
            return (0);
    }
    else
        return (put_error(NULL, NULL, 0));
}