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

void			img_pixel_put(t_data data, int x, int y, int color)
{
	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
		return ;
	*(int *)(data.addr + ((x + y * WIN_W) * data.bit_pixel / 8)) = color;
}

static void		init(int p[2][2], int delta[2], int sign[3], int error[2])
{
	delta[1] = abs(p[1][1] - p[0][1]);
	delta[0] = abs(p[1][0] - p[0][0]);
	sign[1] = p[0][1] < p[1][1] ? 1 : -1;
	sign[0] = p[0][0] < p[1][0] ? 1 : -1;
	error[0] = delta[1] - delta[0];
}

static void		dop(int (*p)[2][2],
	int delta[2], int (*sign)[3], int (*error)[2])
{
	if ((*error)[1] > -delta[0])
	{
		(*error)[0] -= delta[0];
		(*p)[0][1] += (*sign)[1];
	}
	if ((*error)[1] < delta[1])
	{
		(*error)[0] += delta[1];
		(*p)[0][0] += (*sign)[0];
	}
}

void			draw_line1(t_point p1, t_point p2, t_window *wind)
{
	int p[2][2];
	int delta[2];
	int sign[3];
	int error[2];
	int d;

	p[0][1] = p1.x;
	p[1][1] = p2.x;
	p[0][0] = p1.y;
	p[1][0] = p2.y;
	sign[2] = p1.color < p2.color ? 1 : -1;
	init(p, delta, sign, error);
	d = get_color(p1.color, p2.color,
		fmax(abs(p[0][1] - p[1][1]), abs(p[0][0] - p[1][0])));
	if (p[0][1] < 0 || p[0][1] >= WIN_W || p[0][0] < 0 || p[0][0] >= WIN_H ||
		p[1][1] < 0 || p[1][1] >= WIN_W || p[1][0] < 0 || p[1][0] >= WIN_H)
		return ;
	img_pixel_put(wind->data, p[1][1], p[1][0], p2.color);
	while (p[0][1] != p[1][1] || p[0][0] != p[1][0])
	{
		img_pixel_put(wind->data, p[0][1], p[0][0], p1.color);
		error[1] = error[0] * 2;
		p1.color += d * sign[2];
		dop(&p, delta, &sign, &error);
	}
}
