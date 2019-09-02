/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:48:48 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/02 12:51:09 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    format_int(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = 0;
	if (MINUS == '1')
		ZERO = '0';
	if (p->prec > len)
		size = p->prec - len;
	ft_arg_mal(s, len + size, p);
	push_arg_int(s, tmp, len, p);
	// printf("%s| - s\n", *s);
	// printf("%s| - s\n", *s);
	// if (ZERO == '1' && MINUS == '1')
	// 	ZERO = '0';
	// if (PLUS == '1')
	// 	s = form_plus(s);
	// else if (SPACE == '1')
	// 	s = form_space(s);
	// if (p->width > (int)ft_strlen(s))
	// 	s = form_width_minus(s, p);
}