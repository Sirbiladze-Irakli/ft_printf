/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:38 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 21:35:19 by jormond-         ###   ########.fr       */
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
#include "../libft/includes/libft.h"

typedef struct	s_printf
{
	char		flags[5];
	int			width;
	int			prec;
	char		modifier[4];
	char		specifier;
	char		hex_hash[2];
}				t_printf;

int		ft_printf(const char *format, ...);
int     ft_arg_reader(const char *format, int i, va_list ap);
void	distributor(char *buf, va_list ap, t_printf *p);
void	sort_int_chr(char c, va_list ap, t_printf *p);
void	sort_str_ptr(char c, va_list ap, t_printf *p);
void	sort_oct_hex(char c, va_list ap, t_printf *p);
void	sort_bin(char c, va_list ap);
char	*format_str(char *s, t_printf *p);
char    *format_int(char *s, t_printf *p);
char    *format_uint(char *s, t_printf *p);
char    *format_chr(char *s, t_printf *p);
char    *format_ptr(char *s, t_printf *p);
char    *format_oct(char *s, t_printf *p);
char    *format_hex(char *s, t_printf *p);
char    *form_width_minus(char *s, t_printf *p);
char    *form_width_hex(char *s, t_printf *p);
char    *form_prec_hex(char *s, t_printf *p);
char	*form_check_hash(char *s1, t_printf *p);
char	*form_join_zero(char *s1, t_printf *p, int size);
char	*form_wd_zero(char *s1, t_printf *p);
void    form_wd_check_hash(char *s1, t_printf *p);
char    *form_wd_prec_hex(char *s, char *s1, t_printf *p);
char    *form_minus_hex(char *s1, char *s, t_printf *p, int len);
char    *form_zero_hash(char *s, char *s1, t_printf *p);
char	*form_min_hex(char *s, char *s1, t_printf *p);
char    *form_prec(char *s, t_printf *p);
char	*form_plus(char *s);
char	*form_space(char *s);
char    *form_uint_prec(char *s, t_printf *p);
void    parse_struct(char *buf, t_printf *p);
void	struct_init(t_printf *p);
int     width_converter(t_printf *p, char *buf, int i);
int		prec_converter(t_printf *p, char *buf, int i);
int		modif_checker(t_printf *p, char *buf, int i);
int     ft_nbrlen(unsigned long i);
void	front_add_hash(char *s, t_printf *p, int len);
char	*front_add_hex(char *s, t_printf *p);
void    ft_strdup_free(char **s, char *arg);

#endif