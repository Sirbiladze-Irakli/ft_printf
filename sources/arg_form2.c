/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:48:48 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/01 13:49:45 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    format_oct(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = ft_size_mal(len, p);
	ft_arg_mal(s, size, p);
	push_arg_hex_oct(s, tmp, len, p);
	write_arg_hex_oct(*s, size, p);
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