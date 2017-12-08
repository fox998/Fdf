/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:56:05 by afokin            #+#    #+#             */
/*   Updated: 2017/12/07 17:56:07 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lidft.h"

void			red_map(int fd)
{
	char	*line;
	char	***mas;
	t_list	list;
	t_list	*tmp;
	int		y;

	y = 0;
	p_mas = (char ***)malloc(sizeof(char **));
	get_next_line(fd, line);
	mas = ft_strsplit((const char *)line, ' ');
	while (mas[side])
		side++;
	p_mas[y] = (t_point **)malloc(sizeof(t_point *) * (side + 1));
	p_mas[y][side] = NULL;
	while (--side > -1)
		p_mas[y][side] = innit_point(side, y, ft_atoi)
}
