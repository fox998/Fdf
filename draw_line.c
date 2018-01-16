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

// void draw_line1(t_point p1, t_point p2 , void *mlx , void *vim)
// {
//     const int deltaX = abs((int)(p2.x - p1.x));
//     const int deltaY = abs((int)(p2.y - p1.y));
//     const int signX = (int)p1.x < (int)p2.x ? 1 : -1;
//     const int signY = (int)p1.y < (int)p2.y ? 1 : -1;
//     //
//     int error = deltaX - deltaY;
//     //
//     mlx_pixel_put(mlx, vim, (int)p2.x, (int)p2.y, 0xFFFFFF - (int)p2.z);
//     while ((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y) 
//    {
//         mlx_pixel_put(mlx, vim, (int)p1.x, (int)p1.y, 0xFFFFFF - p1.z);
//         p1.z += 16 * 32;
//         const int error2 = error * 2;
//         //
//         if(error2 > -deltaY) 
//         {
//             error -= deltaY;
//             p1.x += signX;
//         }
//         if(error2 < deltaX) 
//         {
//             error += deltaX;
//             p1.y += signY;
//         }
//     }

// }

void draw_line1(t_point p1, t_point p2 , void *mlx , void *vim)
{
    int x1 = p1.x, x2 = p2.x , y1 = p1.y , y2 = p2.y;
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    //const int deltaC = ((p1.color - p2.color));
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    const int signC = p1.color < p2.color ? 1 : -1;
    //
    int error = deltaX - deltaY;
    // int deltaColor;
    // deltaColor = get_color(p1.color, p2.color);

    //int  sc =  5000;
    int d;
    double sqt = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    //d = abs(p1.color - p2.color) / (sqt);
    d = get_color(p1.color, p2.color, sqt);
    //
    mlx_pixel_put(mlx, vim, x2, y2, p2.color);
    while(x1 != x2 || y1 != y2) 
   {
        mlx_pixel_put(mlx, vim, x1, y1, p1.color);
        p1.color += d * signC;
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

void draw_line(int x1, int y1, int x2, int y2 , void *mlx , void *vim)
{
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    //
    int error = deltaX - deltaY;
    //
    mlx_pixel_put(mlx, vim, x2, y2, 0xFFFFFF);
    while(x1 != x2 || y1 != y2) 
   {
        mlx_pixel_put(mlx, vim, x1, y1, 0xFFFFFF);
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
