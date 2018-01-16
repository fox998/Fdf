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

// void			get_point(t_mtr *m, t_point *p , t_point center, int dl)
// {
// 	t_point tmp;
// 	double dz;

// 	tmp = *p;
// 	tmp.x -= center.x;
// 	tmp.y -= center.y;
// 	tmp.z -= center.z;
// 	p->z = (tmp.x * m->m[2][0] + tmp.y * m->m[2][1] + tmp.z * m->m[2][2] + m->m[2][3]);
// 	center.z = (center.x * m->m[2][0] + center.y * m->m[2][1] + center.z * m->m[2][2] + m->m[2][3]);
// 	dz = -(p->z / center.z);
// 	p->x = (tmp.x * m->m[0][0] + tmp.y * m->m[0][1] + tmp.z * m->m[0][2] + m->m[0][3]) * dl / dz;
// 	p->y = (tmp.x * m->m[1][0] + tmp.y * m->m[1][1] + tmp.z * m->m[1][2] + m->m[1][3]) * dl / dz;

// 	//printf("tmp = %f , cnt  = %f \n", tmp.z , center.z);
// 	printf("x = %f , y = %f, z = %f , dz = %f\n",p->x,p->y, p->z, dz );
// }

void			get_point(t_mtr *m, t_point *p , t_point center, int dl)
{
	t_point tmp;
	//double dz;

	//dl = 1;
	tmp = *p;
	tmp.z -= center.z;
	tmp.x = (tmp.x - center.x);
	tmp.y = (tmp.y - center.y);
	p->z = (tmp.x * m->m[2][0] + tmp.y * m->m[2][1] + tmp.z * m->m[2][2] + m->m[2][3]);
	p->x = ((tmp.x * m->m[0][0] + tmp.y * m->m[0][1] + tmp.z * m->m[0][2]) / fabs(p->z / m->m[2][3]  + 1)  + m->m[0][3]) * dl;
	p->y = ((tmp.x * m->m[1][0] + tmp.y * m->m[1][1] + tmp.z * m->m[1][2]) / fabs(p->z / m->m[2][3]  + 1) + m->m[1][3]) * dl;

	//printf("tmp = %f , cnt  = %f \n", tmp.z , center.z);
	//printf("x = %f , y = %f, z = %f\n",p->x,p->y, p->z );
}

// void			get_point(t_mtr *m, t_point *p , t_point center, int dl)
// {
// 	t_point tmp;
// 	//double dz;

// 	tmp = *p;
// 	tmp.z -= center.z;
// 	tmp.x = (tmp.x - center.x);
// 	tmp.y = (tmp.y - center.y);
// 	p->z = (tmp.x * m->m[2][0] + tmp.y * m->m[2][1] + tmp.z * m->m[2][2] + m->m[2][3]) * dl;
// 	center.z = (center.x * m->m[2][0] + center.y * m->m[2][1] + center.z * m->m[2][2] + m->m[2][3]) * dl;
// 	p->x = ((tmp.x * m->m[0][0] + tmp.y * m->m[0][1] + tmp.z * m->m[0][2]) / fabs(p->z/center.z  + 1)  + m->m[0][3]) * dl;
// 	p->y = ((tmp.x * m->m[1][0] + tmp.y * m->m[1][1] + tmp.z * m->m[1][2]) / fabs(p->z/center.z  + 1) + m->m[1][3]) * dl;

// 	//printf("tmp = %f , cnt  = %f \n", tmp.z , center.z);
// 	//printf("x = %f , y = %f, z = %f\n",p->x,p->y, p->z );
// }
