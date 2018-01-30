/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtr_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:48:54 by afokin            #+#    #+#             */
/*   Updated: 2018/01/30 13:48:57 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mtr_rot(t_mtr *mat, double angle_x, double angle_y, double angle_z)
{
	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
	double ad;
	double bd;

	angle_x *= M_PI / 180;
	angle_y *= M_PI / 180;
	angle_z *= M_PI / 180;
	a = cos(angle_x);
	b = sin(angle_x);
	c = cos(angle_y);
	d = sin(angle_y);
	e = cos(angle_z);
	f = sin(angle_z);
	ad = a * d;
	bd = b * d;
	mat->m[0][0] = c * e;
	mat->m[0][1] = -c * f;
	mat->m[0][2] = -d;
	mat->m[1][0] = -bd * e + a * f;
	mat->m[1][1] = bd * f + a * e;
	mat->m[1][2] = -b * c;
	mat->m[2][0] = ad * e + b * f;
	mat->m[2][1] = -ad * f + b * e;
	mat->m[2][2] = a * c;
}
