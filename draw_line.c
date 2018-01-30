/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:02:06 by afokin            #+#    #+#             */
/*   Updated: 2018/01/30 14:02:11 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void img_pixel_put(t_data data, int x, int y, int color)
{
	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
		return ;
	*(int *)(data.addr + ((x + y * WIN_W) * data.bit_pixel / 8)) = color;
}

void draw_line1(t_point p1, t_point p2, t_window *wind)
{
	int x1 = p1.x, x2 = p2.x , y1 = p1.y , y2 = p2.y;
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	const int signC = p1.color < p2.color ? 1 : -1;
	int error = deltaX - deltaY;
	int d;
	double sqt;

	sqt = fmax(abs(x1- x2), abs(y1 - y2));
	d = get_color(p1.color, p2.color, sqt);
	if (x1 < 0 || x1 >= WIN_W || y1 < 0 || y1 >= WIN_H ||
		x2 < 0 || x2 >= WIN_W || y2 < 0 || y2 >= WIN_H)
		return ;
	img_pixel_put(wind->data, x2, y2, p2.color);
	while(x1 != x2 || y1 != y2) 
	{
		img_pixel_put(wind->data, x1, y1, p1.color);
		p1.color += d * signC;
		const int error2 = error * 2;
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
