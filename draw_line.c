/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:03:02 by afokin            #+#    #+#             */
/*   Updated: 2017/12/11 15:03:04 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line1(t_point p1, t_point p2 , void *mlx , void *vim)
{
    const int deltaX = abs((int)(p2.x - p1.x));
    const int deltaY = abs((int)(p2.y - p1.y));
    const int signX = p1.x < p2.x ? 1 : -1;
    const int signY = p1.y < p2.y ? 1 : -1;
    //
    int error = deltaX - deltaY;
    //
    mlx_pixel_put(mlx, vim, (int)p2.x, (int)p2.y, 0xFFFFFF - (int)p2.z);
    while ((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y) 
   {
        mlx_pixel_put(mlx, vim, (int)p1.x, (int)p1.y, 0xFFFFFF - p1.z);
        p1.z += 16 * 32;
        const int error2 = error * 2;
        //
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            p1.x += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            p1.y += signY;
        }
    }

}

void draw_line(int x1, int y1, int x2, int y2 , void *mlx , void *vim)
{
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    //
    int error = deltaX - deltaY;
    //
    mlx_pixel_put(mlx, vim, x2, y2, 0x00FFFF);
    while(x1 != x2 || y1 != y2) 
   {
        mlx_pixel_put(mlx, vim, x1, y1, 0x00FFFF);
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
