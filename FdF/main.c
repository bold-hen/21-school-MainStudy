#include "FdF.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#include <tclDecls.h>

///Структура отвечающая за кодировку цвета в формате RGB
typedef struct      s_color
{
    unsigned char   red;
    unsigned char   grin;
    unsigned char   blue;
}                   t_color;

t_color *ft_init_color()
{
    t_color *result;

    result = (t_color *)malloc(sizeof(t_color));
    if (result == NULL)
        return NULL;
    return result;
}

///Конвертация цвета к int
int ft_color_to_int(t_color *color)
{
    int result;

    result = (int)(color->blue);
    result = result + (int)(color->grin) * 256;
    result = result + (int)(color->red) * 65536;

    return result;
}

///Конвертация int в цвет
t_color *ft_int_to_color(int color)
{
    t_color *result;

    result = ft_init_color();
    if (result == NULL)
        return NULL;
    result->blue = (unsigned char)(color % 256);
    color = color / 256;
    result->grin = (unsigned char)(color % 256);
    color = color / 256;
    result->red = (unsigned char)(color % 256);

    return result;
}

///Объект рисования
typedef struct  s_draw
{
    void *mlx_ptr;
    void *win_ptr;
}               t_draw;

///Точка
typedef struct  s_point
{
    int       x;
    int       y;
}               t_point;

///Прямая линия (определяется 2 точками)
typedef struct  s_line
{
    t_point     *begin;
    t_point     *end;
}               t_line;

///Инициализация линии
t_line *init_line_2D()
{
    t_line *line;

    line = (t_line *)malloc(sizeof(t_line));
    line->begin = (t_point *)malloc(sizeof(t_point));
    if (line->begin == NULL)
        return (NULL);
    line->end = (t_point *)malloc(sizeof(t_point));
    if (line->end == NULL)
        return (NULL);

    line->begin->x = 0;
    line->begin->y = 0;
    line->end->x = 100;
    line->end->y = 200;
    return (line);
}

int ft_sign(int a, int b)
{
    return a < b ? 1 : -1;
}

int ft_abs(int a, int b)
{
    return a < b ? b - a : a - b;
}

t_point *ft_init_point(int x, int y)
{
    t_point *point;

    point = (t_point *)malloc(sizeof(t_point));
    if (point == NULL)
        return NULL;

    point->x = x;
    point->y = y;

    return point;
}

///Нарисовать двумерную линию
void draw_line_2D(t_draw *graphic, t_line *line, int color)
{
    int error;
    int deltaX;
    int deltaY;
    int signX;
    int signY;
    int error2;
    t_point *draw_point;

    draw_point = ft_init_point(line->begin->x, line->begin->y);
    deltaX = ft_abs(line->end->x, line->begin->x);
    deltaY = ft_abs(line->end->y, line->begin->y);
    signX = ft_sign(line->begin->x, line->end->x);
    signY = ft_sign(line->begin->y, line->end->y);
    error = deltaX - deltaY;

    mlx_pixel_put(graphic->mlx_ptr, graphic->win_ptr, line->end->x, line->end->y, color);
    while (draw_point->x != line->end->x || draw_point->y != line->end->y)
    {
        mlx_pixel_put(graphic->mlx_ptr, graphic->win_ptr, draw_point->x, draw_point->y, color);
        error2 = error * 2;
        if (error2 > -deltaY)
        {
            error -= deltaY;
            draw_point->x += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            draw_point->y += signY;
        }
    }
}

///Обработчик нажатия клавиш
int deal_key(int key, void *draw)
{
    if (key == 53) ///Закрытие окна по нажатию на ESC
    {
        exit(0);
    }
    draw_line_2D(draw, init_line_2D(), 60000);

    return (0);
}

///Инициализация объекта рисования
t_draw  *ft_init_draw(int width, int height, char *title)
{
    void *win_ptr;
    void *mlx_ptr;
    t_draw *draw;

    draw = (t_draw *)malloc(sizeof(t_draw));
    if (draw == NULL)
        return (NULL);
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (NULL);
    win_ptr = mlx_new_window(mlx_ptr, width, height, title);
    if (win_ptr == NULL)
        return (NULL);
    draw->mlx_ptr = mlx_ptr;
    draw->win_ptr = win_ptr;
    return (draw);
}

int main(int argc, char **argv)
{
    t_draw *draw; //объект рисования

    draw = ft_init_draw(256, 256, "FDF");
    if (draw == NULL)
        return 0; //Надо поменять на правильную обработку ошибок
    //mlx_key_hook(draw->win_ptr, deal_key, draw);
    draw_line_2D(draw, init_line_2D(), 200);
    mlx_loop(draw->mlx_ptr);


    return 0;
}