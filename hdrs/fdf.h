/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:19:33 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/06 19:41:50 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* --------------------------------- HEADERS -------------------------------- */
# include "../lib/minilibx_macos/mlx.h"
# include "../lib/ft_libft/libft.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "get_next_line.h"
# include "defines.h"
# include "keycodes.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
/* --------------------------------- STRUCTS -------------------------------- */

typedef struct s_point{
	float				pos[3];
	float				spos[3];
	unsigned int		color;
}	t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_data;

typedef struct s_lim
{
	int	min;
	int	max;
}		t_lim;

typedef struct s_dim
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	altitude;
	t_lim			x;
	t_lim			y;
	t_lim			z;
}					t_dim;

typedef struct s_view{
	float	angle;
	float	window_occ;
	float	scale;
	float	z_scale;
}	t_view;

typedef struct s_map{
	t_point	*points;
	int		length;
	int		ll;

}	t_map;

typedef struct s_system{
	t_map	map;
	t_view	view;
	t_dim	dim;
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	*img;
	char	*filename;
}	t_system;
/* -------------------------------- FUNCTIONS ------------------------------- */
void			check_all(int argc, char **argv, t_map *map);
int				f_exit(char *err_message);
int				check_filename(char *file);
int				count_or_check_line(int fd);
int				check_valid(int fd, t_map *map);
void			check_line_points(char **line);
int				count_char(char *str, char c);
int				forbidden_chars(char *str, char *allowed);
void			check_hexadecimal(char *str, char ***tofree);
unsigned int	hexstr_to_int(char *str);
unsigned int	compose_color(unsigned int value, int endian);
char			uppercase(char c);
int				check_num(char *str);
int				check_int(char *s);
int				check_limits_when_10(char *str, int sign);
void			ft_free(char **str);
t_data			*get_img(t_system *sys);
void			load_map(t_system *sys, int fd);
t_point			load_xyz(char *rawvals, int x, int z, int endian);
void			draw_line(t_system *sys, t_point one, t_point two);
void			put_pixel(t_data *img, int x, int y, int color);
void			translate(t_map *map, t_point move);
void			scale(t_map *map, t_point multiplier);
double			deg_to_rad(float degrees);
void			init_dims(t_system *sys);
void			isometric(t_system *sys);
float			get_abs(float num);
void			get_max_dims(t_system *sys);
float			get_scale_factor(t_system *sys);
void			init_view(t_system *sys);
void			render(t_system *sys);
/* ---------------------------------- DEBUG --------------------------------- */
void			debug_split(char **strings);
void			debug_points(t_system *sys);
#endif