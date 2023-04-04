/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:19:33 by jenavarr          #+#    #+#             */
/*   Updated: 2023/04/04 19:19:14 by jenavarr         ###   ########.fr       */
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
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
/* --------------------------------- STRUCTS -------------------------------- */
typedef struct s_point{
	int					pos[3];
	unsigned int		color;
}	t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_data;

typedef struct s_map{
	t_point	*points;
	int		length;
	int		ll;

}	t_map;

typedef struct s_system{
	t_map	map;
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
void			draw_line(t_system *sys, int one[2], int two[2], int color);
void			put_pixel(t_data *img, int x, int y, int color);
/* ---------------------------------- DEBUG --------------------------------- */
void			debug_split(char **strings);
#endif