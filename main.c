#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fdf.h"

int     main(int argc, char **argv)
{
    t_map   map;
    int     fd;

    if (argc == 1)
        return (0);
    fd = open(argv[1], O_RDONLY);
    map.map = get_map(read_map(fd, &(map.max_y)), &(map.max_x), map.max_y);

    int x = 0, y = 0;
    printf("%i %i\n", map.max_x, map.max_y);
    while (y < map.max_y)
    {
        x = 0;
        while (x < map.max_x)
        {
            printf("%i ", map.map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
    // mlx = mlx_init();
    // win = mlx_new_window(mlx, 1000, 1000, "mlx 42");
    // y = 50;
    // while (y < 150)
    // {
    //     x = 50;
    //     while (x < 150)
    //     {
    //         mlx_pixel_put(mlx, win, x, y, 0x00FFFF);
    //         x++;
    //     }
    //     y++;
    // }
    // drawLine(0, 100, 200, 50, mlx, win);
    // mlx_loop(mlx);
}