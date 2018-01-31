/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:34:39 by afokin            #+#    #+#             */
/*   Updated: 2018/01/31 16:34:56 by afokin           ###   ########.fr       */
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
