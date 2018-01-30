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
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define ESC 53
# define RIGHT_ERROW 123
# define LEFT_ERROW 124
# define UP_ERROW 126
# define DOWN_ERROW 125
# define MINUS 78
# define PLUS 69
# define ONE 18
# define TWO 19
# define Q_KEY 12
# define W_KEY 13
# define E_KEY 14
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define SPASE 49

# define WIN_W 800
# define WIN_H 800

typedef struct	s_win
{
	double			m[4][4];
}				t_win;

typedef struct	s_mtr
{
	double			m[4][4];
	double			cz;
}				t_mtr;

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}				t_point;

typedef struct	s_cam
{
	t_point			pos;
}				t_cam;

typedef struct	s_map
{
	int				max_x;
	int				max_y;
	t_point			center;
	int				**map;
	unsigned int	**color;
}				t_map;

typedef struct	s_ing_data
{
	char			*addr;
	int				bit_pixel;
	int				line_size;
	int				endian;
}				t_data;

typedef struct	s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	t_data			data;
	t_map			map;
	t_mtr			mtr;
	int				f;
}				t_window;

void			draw_line1(t_point p1, t_point p2, t_window *wind);
void			draw_line(int x1, int y1, int x2, int y2,
				void *mlx, void *vim);
t_list			*read_map(int fd, int *max_y);
int				**get_map(t_list *lst, int *x, int y);
int				*get_arr_int(char **arr_str, int *x_size);
unsigned int	ft_atoi_hex(char *str, int base);
void			print_map(t_window *mtr);
void			mtr_rot(t_mtr *m, double ang_x, double ang_y, double ang_z);
void			mtr_init(t_mtr *m);
void			get_point(t_mtr *m, t_point *p, t_point center, t_window *wind);
t_point			rotate(t_point point, float angle, t_point cntr);
int				get_color(int color1, int color2, double dl);
void			img_pixel_put(t_data data, int x, int y, int color);

#endif
