/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:19:33 by jenavarr          #+#    #+#             */
/*   Updated: 2023/06/29 20:43:28 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* --------------------------------- HEADERS -------------------------------- */
# include "../lib/ft_libft/libft.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../lib/minilibx_macos/mlx.h"
# include "defines.h"
# include "eventcodes.h"
# include "get_next_line.h"
# include "keycodes.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* --------------------------------- STRUCTS -------------------------------- */

typedef struct s_matrix
{
	float	matrix[3][3];
}			t_matrix;


typedef struct s_point
{
	float			pos[3];
	float			spos[3];
	float			scopypos[3];
	int				color;
}					t_point;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line;
	int				endian;
}					t_data;

typedef struct s_lim
{
	int				min;
	int				max;
}					t_lim;

typedef struct s_dim
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	altitude;
	t_lim			x;
	t_lim			y;
	t_lim			z;
}					t_dim;

typedef struct s_view
{
	float			angle[3];
	float			window_occ;
	float			scale;
	float			z_scale;
}					t_view;

typedef struct s_map
{
	t_point			*points;
	t_point			center;
	int				length;
	int				ll;
	int				change;
	float			zoom;
}					t_map;

typedef struct s_hooks
{
	int				leftclickdownangle[3];
	int				leftclickdownpos[2];
	int				rightclickdownpos[2];
	int				isleftclickdown;
	int				isrightclickdown;
}					t_hooks;

typedef struct s_system
{
	t_map			map;
	t_view			view;
	t_dim			dim;
	t_hooks			hooks;
	void			*mlx_ptr;
	void			*mlx_win;
	t_data			*img;
	char			*filename;
}					t_system;
/* -------------------------------- FUNCTIONS ------------------------------- */
void				check_all(int argc, char **argv, t_map *map);
int					f_exit(char *err_message);
int					check_filename(char *file);
int					count_or_check_line(int fd);
int					check_valid(int fd, t_map *map);
void				check_line_points(char **line);
void				erase_new_line(char *line);
int					count_char(char *str, char c);
int					forbidden_chars(char *str, char *allowed);
void				check_hexadecimal(char *str, char ***tofree);
int					hexstr_to_int(char *str);
int					compose_color(int value, int endian);
char				uppercase(char c);
int					check_num(char *str);
int					check_int(char *s);
int					check_limits_when_10(char *str, int sign);
void				ft_free(char **str);
t_data				*get_img(t_system *sys);
void				load_map(t_system *sys, int fd);
t_point				load_xyz(char *rawvals, int x, int z, int endian);
void				draw_line(t_system *sys, t_point one, t_point two,
						double *s);
void				put_pixel(t_data *img, int x, int y, int color);
void				translate(t_map *map, int x, int y);
void				scale(t_map *map, float mult, int mousex, int mousey);
void				zoom(float *p, float mult, int mousediff[2]);
void				zscale(t_system *sys, float change);
void				rotate(t_system *sys);
void				rot_x(t_system *sys, t_point *tmp, t_point *newpoint);
void				rot_y(t_system *sys, t_point *tmp, t_point *newpoint);
void				rot_z(t_system *sys, t_point *tmp, t_point *newpoint);
float				deg_to_rad(float degrees);
void				init_dims(t_system *sys);
void				angle(t_system *sys, int x, int y, int z);
void				isometric(t_system *sys);
void				parallel(t_system *sys);
float				get_abs(float num);
void				get_max_dims(t_system *sys);
float				get_scale_factor(t_system *sys);
void				init_view(t_system *sys);
void				render(t_system *sys);
void				hook(t_system *sys);
int					keypressed(int keycode, t_system *sys);
void				keypressed_2(int keycode, t_system *sys);
int					mousedown(int button, int x, int y, t_system *sys);
int					mouseup(int button, int x, int y, t_system *sys);
int					mousemove(int x, int y, t_system *sys);
void				clean_img(t_system *sys);
double				*get_color_step(int one, int two, int p);
void				next_color(int *origin, int *color_tmp, int p, \
double *step);
void				get_lowest_distance(t_map *map);
float				get_distance(t_point one, t_point two);
t_point				get_map_center(t_system *sys);
void				change_angle_with_mouse(t_system *sys, int x, int y);
void				clamp_angle(t_system *sys);
int					point_inside_screen(t_point one, t_point two);
int					computeoutcode(float x, float y);
int					cohensutherland(t_point p1, t_point p2);
void				cohensutherland_2(t_point p1, t_point p2, \
int codeout, float *xy);
int					cohenshuterland_3(int codeout, int *code);
void				print_info(t_system *sys);
void				print_angle(t_system *sys);
void				print_zoom(t_system *sys);
void				print_zfactor(t_system *sys);
void				initialize_matrix(t_matrix *m);
t_matrix			multiply_matrices(t_matrix one, t_matrix two);
t_matrix			get_rxyz(t_system *sys);
void				rotate_point(t_point *p, t_matrix rxyz);
/* ---------------------------------- DEBUG --------------------------------- */
void				debug_split(char **strings);
void				debug_points(t_system *sys);
void				debug_line(t_system *sys);
void				debug_colors(t_system *sys);
void				debug_matrix(t_matrix m);
#endif
