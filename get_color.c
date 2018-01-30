/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/12/16 18:39:40 by afokin            #+#    #+#             */
/*   Updated: 2017/12/16 18:39:44 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color(int color1, int color2, double dl)
{
	int		r;
	int		g;
	int		b;
	int		tmp;

	if (color1 < color2)
	{
		tmp = color1;
		color1 = color2;
		color2 = tmp;
	}
	r = ((color1 & 0xFF) - (color2 & 0xFF)) / dl;
	g = (((color1 >> 8) & 0xFF) - ((color2 >> 8) & 0xFF)) / dl;
	b = (((color1 >> 16) & 0xFF) - ((color2 >> 16) & 0xFF)) / dl;
	return (((b << 16) + (g << 8) + r));
}
