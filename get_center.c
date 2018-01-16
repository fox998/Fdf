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
	int 		x;
	int			y;
	long long	sum;

	y = 0;
	sum = 0;
	while (y < m->max_y)
	{
		x = 0;
		while (x < m->max_x)
		{
			sum += m->map[y][x];
			x++;
		}
		y++;
	}
	m->center.x = x / 2;
	m->center.y = y / 2;
	m->center.z = 0;
	//printf("-------------%f\n", m->center.z);
} 
