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

// static void	get_move(t_mtr *mtr , int dl)
// {
// 	t_point dt;

// 	dt.x = WIN_W / 2.0f / dl;
// 	dt.y = WIN_H / 2.0f / dl;
// 	dt.z = 10;

// 	mtr->m[0][3] = dt.x;
// 	mtr->m[1][3] = dt.y;
// 	mtr->m[2][3] = dt.z;
// }

void			rot_center(t_mtr *m, t_point *p)
{
	t_point tmp;
	//double dz;

	//dl = 1;
	tmp = *p;
	p->z = (tmp.x * m->m[2][0] + tmp.y * m->m[2][1] + tmp.z * m->m[2][2]);
	p->x = ((tmp.x * m->m[0][0] + tmp.y * m->m[0][1] + tmp.z * m->m[0][2]) );
	p->y = ((tmp.x * m->m[1][0] + tmp.y * m->m[1][1] + tmp.z * m->m[1][2]) );

	//printf("tmp = %f , cnt  = %f \n", tmp.z , center.z);
	//printf("x = %f , y = %f, z = %f\n",p->x,p->y, p->z );
}

void		print_map(int dl,t_window *wind)
{
	int x;
	int y;

	t_point a , b , c ;

	//get_move(&wind->mtr, dl);
	mlx_put_image_to_window(wind->mlx, wind->win, wind->img, 0, 0);

	y = 0;
	while (y < wind->map.max_y)
	{
		x = 0;
		while (x < wind->map.max_x)
		{
			a.x = x;
			a.y = y;
			a.z = wind->map.map[y][x];
			a.color = 0xFFFFFF - 0x0FFF00 * a.z;

			b.x = a.x;
			b.y = (y + 1);
			if (y != wind->map.max_y - 1)
				b.z = wind->map.map[y + 1][x];
			b.color = 0xFFFFFF - 0x0FFF00 * b.z;

			c.x = (x + 1);
			c.y = a.y;
			if (x != wind->map.max_x - 1)
				c.z = wind->map.map[y][x + 1];
			c.color = 0xFFFFFF - 0x0FFF00 * c.z;

			get_point(&wind->mtr, &a, wind->map.center, dl);
			get_point(&wind->mtr, &b, wind->map.center, dl);
			get_point(&wind->mtr, &c, wind->map.center, dl);
			

			if (x != wind->map.max_x - 1)
				draw_line1(a, c, wind->mlx , wind->win);
			if (y != wind->map.max_y - 1)
				draw_line1(a, b, wind->mlx , wind->win);

			// if (x != wind->map.max_x - 1)
			// 	draw_line(a.x, a.y, c.x, c.y , mlx , win);
			// if (y != wind->map.max_y - 1)
			// 	draw_line(a.x, a.y, b.x, b.y , mlx , win);
			x++;
		}
		y++;
	}
}
