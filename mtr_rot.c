/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtr_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:23:23 by afokin            #+#    #+#             */
/*   Updated: 2017/12/13 18:23:25 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mtr_rot(t_mtr *mat, double angle_x, double angle_y, double angle_z)
{
	angle_x *= M_PI/180;
	angle_y *= M_PI/180;
	angle_z *= M_PI/180;
	double	A       = cos(angle_x);
	double	B       = sin(angle_x);
    double	C       = cos(angle_y);
    double	D       = sin(angle_y);
    double	E       = cos(angle_z);
    double	F       = sin(angle_z);

    double	AD      =   A * D;
    double	BD      =   B * D;

    mat->m[0][0]  =   C * E;
    mat->m[0][1]  =  -C * F;
    mat->m[0][2]  =  -D;
    mat->m[1][0]  = -BD * E + A * F;
    mat->m[1][1]  =  BD * F + A * E;
    mat->m[1][2]  =  -B * C;
    mat->m[2][0]  =  AD * E + B * F;
    mat->m[2][1]  = -AD * F + B * E;
    mat->m[2][2] =   A * C;

    //mat->m[0][3]  =  mat->m[1][3] = mat->m[2][3] = mat->m[3][0] = mat->m[3][1] = mat->m[3][2] = 0;
    mat->m[3][3] =  1;
}
