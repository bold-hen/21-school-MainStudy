#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/includes/libft.h"//потом заменить на стандартный путь

# define BUFF_SIZE 21

typedef struct  s_figure
{
    int x[4];
    int y[4];
}       t_figure;

typedef struct  s_point
{
    int x;
    int y;
}       t_point;

#endif
