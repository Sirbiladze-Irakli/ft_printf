/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:38 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 17:33:44 by jormond-         ###   ########.fr       */
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
	int			dot;
	char		modifier[4];
	char		specifier;
	char		hex_hash[2];
}				t_printf;

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
char	*form_plus(char *s);
char	*form_space(char *s);
char    *form_uint_prec(char *s, t_printf *p);
void	front_add_hash(char *s, t_printf *p, int len);
char	*front_add_hex(char *s, t_printf *p);

		/********************************/
		/* 			input				*/
		/********************************/

int		ft_printf(const char *format, ...);
int     ft_arg_reader(const char *format, int i, va_list ap);
void	distributor(va_list ap, t_printf *p);

		/********************************/
		/* 			struct init			*/
		/********************************/

void    parse_struct(char *buf, t_printf *p);
void	struct_init(t_printf *p);
int     width_converter(t_printf *p, char *buf, int i);
int		prec_converter(t_printf *p, char *buf, int i);
int		modif_checker(t_printf *p, char *buf, int i);

		/********************************/
		/* 			sorter				*/
		/********************************/

void	sort_int(va_list ap, t_printf *p);
void    sort_chr(va_list ap, t_printf *p);
void	sort_str(va_list ap, t_printf *p);
void	sort_ptr(va_list ap, t_printf *p);
void	sort_oct_hex(va_list ap, t_printf *p);
void	sort_bin(char c, va_list ap);

		/********************************/
		/* 			arg format			*/
		/********************************/

void    format_str(char **s, char *tmp, int len, t_printf *p);
char    *format_int(char *s, t_printf *p);
char    *format_uint(char *s, t_printf *p);
void    format_chr(char **s, t_printf *p, char c1);
void    format_ptr(char **s, char *tmp, int len, t_printf *p);
char    *format_oct(char *s, t_printf *p);
char    *format_hex(char *s, t_printf *p);

		/********************************/
		/* 			form tools			*/
		/********************************/

void    form_prec_min(char **s, char *tmp, t_printf *p);
// void    form_width(char **s, int len, char *tmp, t_printf *p);
// void	form_width_char(char **s, int len, char c1, t_printf *p);
void	form_zero(char **s, int size, t_printf *p);
void	ft_arg_mal(char **s, int len, t_printf *p);
void    ft_write_arg(char *s, int len, t_printf *p);
void    ft_write_arg_c(char *s, int len, t_printf *p);
void    ft_push_arg(char **s, char *tmp, t_printf *p);
void    ft_push_arg2(char **s, char *tmp, int size, t_printf *p);
int     ft_size_modif(int len, t_printf *p);
int		ft_size_mal(int len, t_printf *p);
// void    form_prec_max(char **s, t_printf *p);

		/********************************/
		/* 			another tools		*/
		/********************************/

int     ft_nbrlen(unsigned long i);
void    ft_strdup_free(char **s, char *arg, t_printf *p);
void	ft_strsub_free(char **s, char *tmp, t_printf *p);

#endif