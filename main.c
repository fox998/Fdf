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
    get_center(&map);
    
}