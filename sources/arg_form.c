/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:24:07 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/28 19:45:46 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    format_str(char **s, char *tmp, t_printf *p)
{
	if (ZERO && MINUS)
		ZERO = '0';
	if (p->prec < 0 && p->dot == 1)
		p->prec = 0;
	if (p->prec < (int)ft_strlen(tmp))
		form_prec_min(s, tmp, p);
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

char    *format_chr(char *s, t_printf *p)
{
	p->prec = 0;
	// if (ZERO && MINUS)
	// 	ZERO = '0';
    // if (p->width > (int)ft_strlen(s))
	// 	s = form_width_minus(s, p);
	return (s);
}

char    *format_ptr(char *s, t_printf *p)
{
	p->prec = 0;
	// if (p->prec > p->width)
	// {
	// 	ZERO = '1';
	// 	p->width = p->prec;
	// 	s = form_width_minus(s, p);
	// 	s = ft_strjoin("0x", s);
	// }
	// else
	// {
	// 	if (ZERO == '1' && MINUS == '1')
	// 		ZERO = '0';
	// 	s = form_prec(s, p);
	// 	s = ft_strjoin("0x", s);
	// 	if (p->width > (int)ft_strlen(s))
	// 		s = form_width_minus(s, p);
	// }
	return (s);
}