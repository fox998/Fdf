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

void			get_point(t_mtr *m, t_point *p, t_point center, t_window *wind)
{
	t_point	tmp;
	double	dz;

	tmp = *p;
	tmp.x = (tmp.x - center.x) * m->m[3][3];
	tmp.y = (tmp.y - center.y) * m->m[3][3];
	tmp.z *= m->m[3][3];
	p->z = (tmp.x * m->m[2][0] + tmp.y * m->m[2][1] + tmp.z * m->m[2][2]);
	dz = p->z / (-m->m[2][3] * m->m[3][3]) * wind->f + 1;
	p->z *= m->m[3][3];
	p->x = ((tmp.x * m->m[0][0] + tmp.y * m->m[0][1]
		+ tmp.z * m->m[0][2]) / dz + m->m[0][3]);
	p->y = ((tmp.x * m->m[1][0] + tmp.y * m->m[1][1]
		+ tmp.z * m->m[1][2]) / dz + m->m[1][3]);
}
