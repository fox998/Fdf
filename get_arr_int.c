/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:27:41 by afokin            #+#    #+#             */
/*   Updated: 2017/12/11 15:27:43 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*get_arr_int(char **arr_str, int *x_size)
{
	int		*arr;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (arr_str[size])
		size++;
	if ((*x_size != -1 && *x_size != size) || size == 0)
	{
		ft_putstr("Error: incorrect map format\n");
		exit(0);
	}
	*x_size = size;
	arr = (int *)malloc(sizeof(int) * (size + 1));
	while (i < size)
	{
		arr[i] = ft_atoi(arr_str[i]);
		free(arr_str[i]);
		i++;
	}
	free(arr_str);
	return (arr);
}
