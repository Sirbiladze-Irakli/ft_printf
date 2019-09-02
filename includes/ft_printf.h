/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:38 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/02 19:32:40 by jormond-         ###   ########.fr       */
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
	char		modifier[20];
	int			count_mod;
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

int		sort_int(va_list ap, t_printf *p);
int		sort_uint(va_list ap, t_printf *p);
int	    sort_chr(va_list ap, t_printf *p);
int		sort_str(va_list ap, t_printf *p);
int		sort_ptr(va_list ap, t_printf *p);
int		sort_hex(va_list ap, t_printf *p);
int		sort_oct(va_list ap, t_printf *p);
int		sort_per(t_printf *p);
int		sort_bin(char c, va_list ap);

		/********************************/
		/* 			arg format			*/
		/********************************/

void    format_str(char **s, char *tmp, int len, t_printf *p);
void    format_int(char **s, char *tmp, int len, t_printf *p);
void    format_chr(char **s, t_printf *p);
void    format_ptr(char **s, char *tmp, int len, t_printf *p);
void    format_oct(char **s, char *tmp, int len, t_printf *p);
void    format_hex(char **s, char *tmp, int len, t_printf *p);
void	format_per(char **s, char tmp, t_printf *p);

		/********************************/
		/* 			form tools			*/
		/********************************/

void    form_prec_min(char **s, char *tmp, t_printf *p);
void	form_zero(char **s, int size, t_printf *p);
void	ft_arg_mal(char **s, int len, t_printf *p);
void    ft_push_arg(char **s, char *tmp, t_printf *p);
void    ft_push_arg2(char **s, char *tmp, int size, t_printf *p);
void    push_arg_hex_oct(char **s, char *tmp, int len, t_printf *p);
void    push_arg_int(char **s, char *tmp, int len, t_printf *p);
void	push_hash(char **s, int calibr, int len, t_printf *p);
int		calibr_o_x(int calibr, t_printf *p);
int     push_zero(char **s, int calibr, int len, t_printf *p);
int		cut_front_zero(char **s, t_printf *p);
void    cut_zero(char **s, int len, t_printf *p);
char	*whats_hash(t_printf *p);
int		calibration_of_prec(int len, t_printf *p);
int     ft_size_modif(int len, t_printf *p);
int		ft_size_mal(int len, t_printf *p);
int     fill_plus_or_space(char **s, int calibr, t_printf *p);
void    var_sign_modif(long long *arg, t_printf *p);
void    var_unsign_modif(unsigned long long *arg, t_printf *p);
void    push_per(char **s, char tmp, t_printf *p);

		/********************************/
		/* 			another tools		*/
		/********************************/

int     ft_nbrlen(unsigned long i);
void    write_arg(char *s, int len, t_printf *p);
void    write_arg_c(char *s, int len, t_printf *p);
void    write_arg_hex_oct(char *s, int size, t_printf *p);
void    write_arg_int(char *s, int len, t_printf *p);
void    ft_strdup_free(char **s, char *arg, t_printf *p);
void	ft_strsub_free(char **s, char *tmp, t_printf *p);
char	*ft_itoa_base_c(unsigned long long value, int base, char c);
void	int_len_modif(int *len, t_printf *p);


#endif