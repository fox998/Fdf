/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:27:53 by afokin            #+#    #+#             */
/*   Updated: 2018/01/30 13:27:58 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fdf.h"

static void	get_move(t_mtr *mtr, t_map *m)
{
	mtr->m[3][3] = ft_max(ft_max(WIN_W, WIN_H) /
		(ft_max(m->max_x, m->max_y) * 2), 1);
	mtr->m[0][3] = WIN_W / 2.0f;
	mtr->m[1][3] = WIN_H / 2.0f;
	mtr->m[2][3] = -2 * ft_max(m->max_x, m->max_y);
	m->center.x = m->max_x / 2;
	m->center.y = m->max_y / 2;
}

static int	key_funct(int key, void *param)
{
	static int	x = 0;
	static int	y = 0;
	static int	z = 0;
	int			grad;
	int			scl;

	grad = 10;
	scl = 2;
	if (key == ESC)
		exit(0);
	else
	{
		if (key == W_KEY)
			x += grad;
		else if (key == S_KEY)
			x -= grad;
		else if (key == A_KEY)
			y += grad;
		else if (key == D_KEY)
			y -= grad;
		else if (key == Q_KEY)
			z += grad;
		else if (key == E_KEY)
			z -= grad;
		else if (key == ONE)
			((t_window *)param)->f = 0;
		else if (key == TWO)
			((t_window *)param)->f = 1;
		else if (key == MINUS && ((t_window *)param)->mtr.m[3][3] > 2)
			((t_window *)param)->mtr.m[3][3] -= scl;
		else if (key == PLUS && ((t_window *)param)->mtr.m[3][3] < 30)
			((t_window *)param)->mtr.m[3][3] += scl;
		else if (key == SPASE)
		{
			x = 0;
			y = 0;
			z = 0;
			get_move(&((t_window *)param)->mtr, &((t_window *)param)->map);
		}
		mtr_rot(&((t_window *)param)->mtr, x, y, z);
		print_map((t_window *)param);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_window	wind;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	wind.map.map = get_map(read_map(fd, &(wind.map.max_y)),
		&(wind.map.max_x), wind.map.max_y);
	close(fd);
	get_move(&wind.mtr, &wind.map);
	mtr_rot(&wind.mtr, 0, 0, 0);
	wind.f = 1;
	wind.mlx = mlx_init();
	wind.win = mlx_new_window(wind.mlx, WIN_H, WIN_W, "mlx 42");
	wind.img = mlx_new_image(wind.mlx, WIN_W, WIN_H);
	wind.data.addr = mlx_get_data_addr(wind.img,
		&wind.data.bit_pixel, &wind.data.line_size, &wind.data.endian);
	print_map(&wind);
	mlx_hook(wind.win, 2, 5, key_funct, &wind);
	mlx_loop(wind.mlx);
}
