/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:39:40 by afokin            #+#    #+#             */
/*   Updated: 2017/12/16 18:39:44 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color(int Color1, int Color2, double dl)
{
	int		R;
	int		G;
	int		B;
	int		tmp;

	if (Color1 < Color2)
	{
		tmp = Color1;
		Color1 = Color2;
		Color2 = tmp;
	}
	R = ((Color1 & 0xFF) - (Color2 & 0xFF)) / dl;
	G = (((Color1 >> 8) & 0xFF) - ((Color2 >> 8) & 0xFF)) / dl;
	B = (((Color1 >> 16) & 0xFF) - ((Color2 >> 16) & 0xFF)) / dl;
	return (((B << 16) + (G << 8) + R) );
}
