#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fdf.h"

int     main(int argc, char **argv)
{
    t_map   map;
    t_mtr   mat;
    int     fd;
    int 	dl;
    //t_mtr   m;

    dl = 20;
    mtr_init(&mat);
    mtr_rot(&mat, 15, 0, 30);
    if (argc == 1)
        return (0);
    fd = open(argv[1], O_RDONLY);
    map.map = get_map(read_map(fd, &(map.max_y)), &(map.max_x), map.max_y);
    close(fd);
    get_center(&map);



    print_map(&map, 10, 800, 800 , &mat);
    
}