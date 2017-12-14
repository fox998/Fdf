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
#include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct	s_mtr
{
	double			m[4][4];
}				t_mtr;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_cam
{
	t_point		pos;
}				t_cam;

typedef struct	s_map
{
	int				max_x;
	int				max_y;
	t_point			center;
	int				**map;
	unsigned int	**color;
}				t_map;

void 			draw_line1(t_point p1, t_point p2 , void *mlx , void *vim);
void			draw_line(int x1, int y1, int x2, int y2 , void *mlx , void *vim);
t_list			*read_map(int fd ,int *max_y);
int				**get_map(t_list *lst, int *x , int y);
int				*get_arr_int(char **arr_str, int *x_size);
void			get_center(t_map *m);
unsigned int	ft_atoi_hex(char *str, int base);
void			print_map(t_map *m ,int dl, int w_h, int w_w, t_mtr *mtr);
void			mtr_rot(t_mtr *m, double ang_x, double ang_y, double ang_z);
void			mtr_init(t_mtr *m);
void			get_point(t_mtr *m, t_point *p, t_point center);
t_point 		rotate(t_point point, float angle, t_point cntr);

#endif
