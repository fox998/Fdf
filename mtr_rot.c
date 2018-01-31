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
	double c_xyz[3];
	double s_xyz[3];

	angle_x *= M_PI / 180;
	angle_y *= M_PI / 180;
	angle_z *= M_PI / 180;
	c_xyz[0] = cos(angle_x);
	s_xyz[0] = sin(angle_x);
	c_xyz[1] = cos(angle_y);
	s_xyz[1] = sin(angle_y);
	c_xyz[2] = cos(angle_z);
	s_xyz[2] = sin(angle_z);
	mat->m[0][0] = c_xyz[1] * c_xyz[2];
	mat->m[0][1] = -c_xyz[1] * s_xyz[2];
	mat->m[0][2] = -s_xyz[1];
	mat->m[1][0] = -(s_xyz[0] * s_xyz[1]) * c_xyz[2] + c_xyz[0] * s_xyz[2];
	mat->m[1][1] = s_xyz[0] * s_xyz[1] * s_xyz[2] + c_xyz[0] * c_xyz[2];
	mat->m[1][2] = -s_xyz[0] * c_xyz[1];
	mat->m[2][0] = c_xyz[0] * s_xyz[1] * c_xyz[2] + s_xyz[0] * s_xyz[2];
	mat->m[2][1] = -(c_xyz[0] * s_xyz[1]) * s_xyz[2] + s_xyz[0] * c_xyz[2];
	mat->m[2][2] = c_xyz[0] * c_xyz[1];
}
