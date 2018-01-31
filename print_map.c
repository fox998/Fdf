/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:23:04 by afokin            #+#    #+#             */
/*   Updated: 2017/12/13 16:23:06 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		clean_img(char *addr, int size, int bit_pixel)
{
	int x;

	x = 0;
	while (x < size)
	{
		*(int *)(addr + ((x) * bit_pixel / 8)) = 0;
		x++;
	}
}

static void		get_poit_map(t_window *wind,
	t_point poit_map[wind->map.max_y][wind->map.max_x])
{
	int		x;
	int		y;
	t_point	a;

	y = 0;
	while (y < wind->map.max_y)
	{
		x = 0;
		while (x < wind->map.max_x)
		{
			a.x = x;
			a.y = y;
			a.z = wind->map.map[y][x];
			if ((a.color = 0xFFFFFF - 0x0FFF00 * wind->map.map[y][x]) < 1)
				a.color = 0x000068;
			get_point(&wind->mtr, &a, wind->map.center, wind);
			(poit_map)[y][x] = a;
			x++;
		}
		y++;
	}
}

static void		check_yx(t_window *wind, int *y, int *x,
	t_point poit_map[wind->map.max_y][wind->map.max_x])
{
	*y = wind->map.max_y;
	*x = wind->map.max_x;
	if (poit_map[0][0].z >= poit_map[0][wind->map.max_x - 1].z)
		*x = -1;
	if (poit_map[0][0].z >= poit_map[wind->map.max_y - 1][0].z)
		*y = -1;
}

static void		draw(int yx[2], int sign[2], t_window *wind,
	t_point poit_map[wind->map.max_y][wind->map.max_x])
{
	int	x;
	int	y;

	y = yx[0];
	x = yx[1];
	img_pixel_put(wind->data, poit_map[y][x].x,
		poit_map[y][x].y, poit_map[y][x].color);
	if ((x < wind->map.max_x - 1 && sign[1] == 1) || (x > 0 && sign[1] == -1))
		draw_line1(poit_map[y][x], poit_map[y][x + sign[1]], wind);
	if ((y < wind->map.max_y - 1 && sign[0] == 1) || (y > 0 && sign[0] == -1))
		draw_line1(poit_map[y][x], poit_map[y + sign[0]][x], wind);
}

void			print_map(t_window *wind)
{
	int		yx[2];
	int		sign[2];
	t_point	poit_map[wind->map.max_y][wind->map.max_x];

	clean_img(wind->data.addr, (WIN_W) * (WIN_H - 1), wind->data.bit_pixel);
	mlx_put_image_to_window(wind->mlx, wind->win, wind->img, 0, 0);
	get_poit_map(wind, poit_map);
	check_yx(wind, yx, yx + 1, poit_map);
	sign[0] = (*yx == -1 ? 1 : -1);
	sign[1] = (yx[1] == -1 ? 1 : -1);
	while ((*yx += sign[0]) != wind->map.max_y && *yx != -1)
	{
		yx[1] = sign[1] > 0 ? -1 : wind->map.max_x;
		while ((yx[1] += sign[1]) != wind->map.max_x && yx[1] != -1)
			draw(yx, sign, wind, poit_map);
	}
	mlx_put_image_to_window(wind->mlx, wind->win, wind->img, 0, 0);
}
