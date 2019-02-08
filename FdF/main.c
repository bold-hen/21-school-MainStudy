#include "FdF.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int g_x = 0;
int g_y = 0;

typedef struct s_draw
{
    void *mlx_ptr;
    void *win_ptr;
} t_draw;

int deal_key(int key, void *draw)
{
    if (key == 124)
    {
        g_x += 4;
        //right
    }
    if (key == 125)
    {
        g_y += 4;
        //bottom
    }
    if (key == 126)
    {
        g_y -= 4;
        //top
    }
    if (key == 123)
    {
        g_x -= 4;
        //left
    }
    mlx_clear_window(((t_draw *)draw)->mlx_ptr, ((t_draw *)draw)->win_ptr);
    mlx_pixel_put(((t_draw *)draw)->mlx_ptr, ((t_draw *)draw)->win_ptr, g_x, g_y, 0xFFFFFF);
    return (0);
}

int main(int argc, char **argv)
{
    void *win_ptr;
    void *mlx_ptr;
    t_draw *draw;

    draw = (t_draw *)malloc(sizeof(t_draw));
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 300, 300, "test");
    mlx_pixel_put(mlx_ptr, win_ptr, g_x, g_y, 0xFFFFFF);
    draw->mlx_ptr = mlx_ptr;
    draw->win_ptr = win_ptr;
    mlx_key_hook(win_ptr, deal_key, draw);
    mlx_loop(mlx_ptr);
    return 0;
}