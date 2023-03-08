/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:14:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/14 13:14:59 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_vars
{
	int			i;
	int			len;
	int			w;
	va_list		lst;
}				t_vars;

int	ft_printf(char const *str, ...);

int	ft_print_str(char *str);
int	ft_print_int(int i);
int	ft_print_hexlow(unsigned long long dec);
int	ft_print_hexupp(unsigned long long dec);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_unsigned(unsigned int i);
int	ft_print_char(char c);

#endif