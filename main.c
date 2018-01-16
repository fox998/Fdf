#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fdf.h"

static int key_funct(int key, void *param)
{
    static int x = 0, y = 0, z = 0;
    printf("key = %i\n", key);
    if (key == ESC)
        exit(0);
    else if (key == W_KEY)
    {
        x += 15;
        mtr_rot(&((t_window *)param)->mtr, x, y, z);
        print_map(20, (t_window *)param);
    }
    param = 0;
    return (0);
}

static void get_move(t_mtr *mtr , int dl)
{
    t_point dt;

    //dl = 1;
    dt.x = WIN_W / 2.0f / dl;
    dt.y = WIN_H / 2.0f / dl;
    dt.z = -10;

    mtr->m[0][3] = dt.x;
    mtr->m[1][3] = dt.y;
    mtr->m[2][3] = dt.z;
}

int     main(int argc, char **argv)
{
    int         fd;
    int         dl;
    t_window    wind;

    dl = 20;
    mtr_init(&wind.mtr);
    if (argc == 1)
        return (0);
    fd = open(argv[1], O_RDONLY);
    wind.map.map = get_map(read_map(fd, &(wind.map.max_y)), &(wind.map.max_x), wind.map.max_y);
    close(fd);
    get_center(&wind.map);
    get_move(&wind.mtr, dl);
    mtr_rot(&wind.mtr, 0, 0, 0);
    wind.mlx = mlx_init();
    wind.win = mlx_new_window(wind.mlx, WIN_H, WIN_W, "mlx 42");
    wind.img = mlx_new_image(wind.mlx , WIN_W, WIN_H);

    print_map(dl, &wind);

    mlx_key_hook(wind.win, key_funct, &wind);
    mlx_loop(wind.mlx);
}