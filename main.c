#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libft/libft.h>
#include <mlx.h>


void drawLine(int x1, int y1, int x2, int y2 , void *mlx , void *vim) {
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    //
    int error = deltaX - deltaY;
    //
    mlx_pixel_put(mlx, vim, x2, y2, 0x00FF00);
    while(x1 != x2 || y1 != y2) 
   {
        mlx_pixel_put(mlx, vim, x1, y1, 0x00FF00);
        const int error2 = error * 2;
        //
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }

}

int        main(void)
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "mlx 42");
    y = 50;
    while (y < 150)
    {
        x = 50;
        while (x < 150)
        {
            mlx_pixel_put(mlx, win, x, y, 0x00FFFF);
            x++;
        }
        y++;
    }
    drawLine(0, 100, 200, 50, mlx, win);
    mlx_loop(mlx);
}