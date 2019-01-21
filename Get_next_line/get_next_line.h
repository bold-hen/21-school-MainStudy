#ifndef _GET_NEXT_LINE_
#define _GET_NEXT_LINE_

#include "libft/libft.h"

int get_next_line(const int fd, char **line);

typedef struct  s_line
{
    int         fd;
    char        *line;
}               t_line;

#define BUFF_SIZE 32

#endif
