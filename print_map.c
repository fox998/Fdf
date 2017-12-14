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

void		print_map(t_map *m ,int dl, int w_h, int w_w, t_mtr *mtr)
{
	int x;
	int y;
	void	*mlx;
	void	*win;
	// float	tmp_x;
	//float	tmp_y;

	t_point a , b , c;

	mlx = mlx_init();
	win = mlx_new_window(mlx, w_h, w_w, "mlx 42");

	int dx, dy;
	dl = 10;
	dx = w_w / 2 ;//- (m->center.x * dl) / 2;
	// printf("cen.x = %f\n", m->center.x);
	// printf("cen.x = %d\n", dl);
	// printf("cen.x = %f\n", m->center.x * dl);
	// dx = (w_w - m->center.x * dl) / 2;
	dy = w_h / 2;// - (m->center.y * dl) / 2;
	y = 0;
	while (y < m->max_y)
	{
		x = 0;
		while (x < m->max_x)
		{
			// tmp_x = get_ax(mtr, 0, x*dl + dx);
			//tmp_y = get_ax(mtr, 1, y*dl + dy);
			a.x = x;
			a.y = y;
			a.z = m->map[y][x];

			b.x = a.x;
			b.y = (y + 1);
			if (y != m->max_y - 1)
				b.z = m->map[y + 1][x];

			c.x = (x + 1);
			c.y = a.y;
			if (x != m->max_x - 1)
				c.z = m->map[y][x + 1];

			get_point(mtr, &a, m->center);
			get_point(mtr, &b, m->center);
			get_point(mtr, &c, m->center);
			// int angle = 45;
			// a = rotate(a, angle, m->center);
			// b = rotate(b, angle, m->center);
			// c = rotate(c, angle, m->center);

			a.x = a.x * dl + dx;
			a.y = a.y * dl + dy;

			b.x = b.x * dl + dx;
			b.y = b.y * dl + dy;

			c.x = c.x * dl + dx;
			c.y = c.y * dl + dy;
			//tmp_y = ((float)(y * get_ax(mtr, 1) * dl) + dy);
			if (x != m->max_x - 1)
				draw_line(a.x, a.y, c.x, c.y , mlx , win);
			if (y != m->max_y - 1)
				draw_line(a.x, a.y, b.x, b.y , mlx , win);
			x++;
		}
		y++;
	}


	mlx_loop(mlx);
}
