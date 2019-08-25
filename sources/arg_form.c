/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:24:07 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:02:41 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char    *format_str(char *s, t_printf *p)
{
	if (ZERO && MINUS)
		ZERO = '0';
	s = form_prec(s, p);
    if (p->width > (int)ft_strlen(s))
		s = form_width_minus(s, p);
	return (s);
}

char    *format_int(char *s, t_printf *p)
{
	if (ZERO == '1' && MINUS == '1')
		ZERO = '0';
	if (PLUS == '1')
		s = form_plus(s);
	else if (SPACE == '1')
		s = form_space(s);
	if (p->width > (int)ft_strlen(s))
		s = form_width_minus(s, p);
	return (s);
}

char    *format_uint(char *s, t_printf *p)
{
	if (ZERO == '1' && MINUS == '1')
		ZERO = '0';
	if (p->width > (int)ft_strlen(s))
		s = form_width_minus(s, p);
	return (s);
}