/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:38 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/21 22:38:46 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 64
# define ZERO p->flags[0]
# define MINUS p->flags[1]
# define PLUS p->flags[2]
# define HASH p->flags[3]
# define SPACE p->flags[4]

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct	s_printf
{
    char		formated[BUFF_SIZE];
	char		flags[5];
	int			width;
	int			prec;
	char		modifier[4];
	char		specifier;
}				t_printf;

int     ft_arg_reader(const char *format, int i, va_list ap);
void	distributor(char *buf, va_list ap, t_printf *p);
void	sort_int_arg(char c, va_list ap, char *buf);
void	sort_str_ptr(char c, va_list ap, char *buf);
void	sort_oct_hex(char c, va_list ap, char *buf);
void	sort_bin(char c, va_list ap);
void	format_str(char *s, char *buf);
void	form_width_minus(char *s, char *width, int minus);
void    parse_struct(char *buf, t_printf *p);
void	struct_init(t_printf *p);
int     width_converter(char *buf, int i);

#endif