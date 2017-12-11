/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:10:46 by afokin            #+#    #+#             */
/*   Updated: 2017/12/11 15:10:48 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**get_map(t_list *lst, int *x , int y)
{
	int 		**map;
	t_list		*tmp;
	int			i;

	map = (int **)malloc(sizeof(int *) * (y + 1));
	i = 0;
	while (lst->next)
	{
		map[i] = get_arr_int(ft_strsplit(lst->content, ' '), x);
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
		i++;
	}
	return (map);
}
