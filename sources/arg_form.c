/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:24:07 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 18:33:40 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    format_str(char **s, char *tmp, int len, t_printf *p)
{
	ZERO = '0';
	ft_arg_mal(s, len, p);
	if (p->prec < 0 && p->dot == 1)
		p->prec = 0;
	ft_push_arg(s, tmp, p);
	
}

void    format_chr(char **s, t_printf *p, char c1)
{
	int		len;

	p->prec = 0;
	ZERO = '0';
	ft_arg_mal(s, 1, p);
	if ((len = p->width - 1) < 0)
		len = 0;
}

void    format_ptr(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = ft_size_mal(len, p);
	ft_arg_mal(s, size, p);
	printf("%s| - s\n", *s);
	// printf("%s| - s\n", *s);
	// ft_push_arg(s, tmp, p);
}

char    *format_int(char *s, t_printf *p)
{
	p->prec = 0;
	// if (ZERO == '1' && MINUS == '1')
	// 	ZERO = '0';
	// if (PLUS == '1')
	// 	s = form_plus(s);
	// else if (SPACE == '1')
	// 	s = form_space(s);
	// if (p->width > (int)ft_strlen(s))
	// 	s = form_width_minus(s, p);
	return (s);
}

char    *format_uint(char *s, t_printf *p)
{
	p->prec = 0;
	// if (ZERO == '1' && MINUS == '1')
	// 	ZERO = '0';
	// s = form_uint_prec(s, p);
	// if (p->width > (int)ft_strlen(s))
	// 	s = form_width_minus(s, p);
	return (s);
}

