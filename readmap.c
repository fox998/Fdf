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

#include "fdf.h"

t_list			*read_map(int fd, int *max_y)
{
	char	*line;
	t_list	*list;
	t_list	*tmp;
	int		y;

	list = (t_list *)malloc(sizeof(t_list));
	tmp = list;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		tmp->content = (void *)line;
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	*max_y = y;
	if (y == 0)
	{
		ft_putstr("Error: enpty file\n");
		exit(0);
	}
	return (list);
}
