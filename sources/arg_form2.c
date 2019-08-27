/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:48:48 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 18:17:38 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char    *format_oct(char *s, t_printf *p)
{
	if (HASH == '1')
		s = ft_strjoin("0", s);
	if (ZERO == '1' && MINUS == '1')
		ZERO = '0';
	if (p->prec > (int)ft_strlen(s))
		s = form_prec(s, p);
	if (p->width > (int)ft_strlen(s))
		s = form_width_minus(s, p);
	return (s);
}

char    *format_hex(char *s, t_printf *p)
{
	char	*s1;
	if (ZERO == '1' && MINUS == '1')
		ZERO = '0';
	if (MINUS == '1')
		s = front_add_hex(s, p);
	// if (p->prec >= 0)
	// 	ZERO = '0';
	// if (p->prec >= p->width)
	// 	s = form_prec_hex(s, p);
	// else
	// 	s = form_width_hex(s, p);
	return (s);
}