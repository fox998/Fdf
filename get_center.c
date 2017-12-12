/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:52:16 by afokin            #+#    #+#             */
/*   Updated: 2017/12/12 16:52:19 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_center(t_map *m)
{
	int 	i;
	int		y;
	int		max_z;
	int		min_z;

	y = 0;
	min_z = 2147483647;
	max_z = −2147483648;

	while (y < m->max_y)
	{
		x = 0;
		while (x < m->max_x)
		{
			if (m->map[y][x] > max_z)
				max_z = m->map[y][x];
			if (m->map[y][x] < min_z)
				min_z = m->map[y][x];
		}
	}
	m->center.x = x / 2;
	m->center.y = y / 2;
	m->center.z = (min_z + max_z) / 2;
} 
