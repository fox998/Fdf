/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:07:18 by afokin            #+#    #+#             */
/*   Updated: 2017/12/13 19:07:20 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point rotate(t_point point, float angle, t_point cntr)
{
           t_point rotated_point;
           angle = angle / 180 * M_PI;
           rotated_point.x = (point.x - cntr.x) * cos(angle) - (point.y - cntr.y) * sin(angle);
           rotated_point.y = (point.x - cntr.x) * sin(angle) + (point.y - cntr.y) * cos(angle);
           return rotated_point;
}

void			get_point(t_mtr *m, t_point *p , t_point center)
{
	//float ax;
	t_point tmp;
	//int i;

	//ax = 0;
	//i = 0;
	tmp = *p;
	tmp.x -= center.x;
	tmp.y -= center.y;
	tmp.z -= center.z;
	p->x = tmp.x * m->m[0][0] + tmp.y * m->m[0][1] + tmp.z * m->m[0][2];
	p->y = tmp.x * m->m[1][0] + tmp.y * m->m[1][1] + tmp.z * m->m[1][2];
	p->z = tmp.x * m->m[2][0] + tmp.y * m->m[2][1] + tmp.z * m->m[2][2];
	// while (i < 3)
	// {
	// 	ax += m->m[n][i];
	// 	printf("%f ", m->m[n][i]);
	// 	i++;
	// }
	// printf("%i\n", n);
	//return (ax);
}
