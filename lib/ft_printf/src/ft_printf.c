/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:52:59 by jenavarr          #+#    #+#             */
/*   Updated: 2022/06/01 18:57:12 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	get_type(char c, t_vars *lst)
{
	if (c == 's')
		return (ft_print_str(va_arg(lst->lst, char *)));
	else if (c == '%')
		return (ft_print_str("%"));
	else if (c == 'c')
		return (ft_print_char(va_arg(lst->lst, int)));
	else if (c == 'i' || c == 'd')
		return (ft_print_int(va_arg(lst->lst, int)));
	else if (c == 'x')
		return (ft_print_hexlow(va_arg(lst->lst, unsigned int)));
	else if (c == 'X')
		return (ft_print_hexupp(va_arg(lst->lst, unsigned int)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(lst->lst, unsigned long long)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(lst->lst, unsigned long)));
	return (0);
}

static void	func(t_vars *vars, char const *str)
{
	vars->i++;
	vars->w = get_type(str[vars->i], vars);
	vars->len += vars->w;
}

static void	func1(t_vars *vars, char const *str)
{
	vars->w = ft_print_char(str[vars->i]);
	vars->len += vars->w;
}

int	ft_printf(char const *str, ...)
{
	t_vars	vars;

	vars.len = 0;
	vars.i = 0;
	va_start(vars.lst, str);
	while (str[vars.i])
	{
		if (str[vars.i] == '%' && str[vars.i + 1] != '\0')
		{
			func(&vars, str);
			if (vars.w == -1)
				return (-1);
		}
		else
		{
			func1(&vars, str);
			if (vars.w == -1)
				return (-1);
		}
		vars.i++;
	}
	va_end(vars.lst);
	return (vars.len);
}
