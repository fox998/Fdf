/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:30:59 by afokin            #+#    #+#             */
/*   Updated: 2017/12/08 18:31:00 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

void			draw_line(int x1, int y1, int x2, int y2 , void *mlx , void *vim);
t_list			*read_map(int fd ,int *max_y);
int				**get_map(t_list *lst, int *x , int y);
int				*get_arr_int(char **arr_str, int *x_size);


typedef struct	s_map
{
	int		max_x;
	int		max_y;
	int		**map;
}				t_map;

#endif
