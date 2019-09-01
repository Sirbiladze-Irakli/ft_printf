/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:24:07 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/01 13:48:26 by jormond-         ###   ########.fr       */
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
	push_arg_hex_oct(s, tmp, len, p);
	write_arg_hex_oct(*s, size, p);
}

void    format_hex(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = ft_size_mal(len, p);
	ft_arg_mal(s, size, p);
	push_arg_hex_oct(s, tmp, len, p);
	write_arg_hex_oct(*s, size, p);
}

void    format_int(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = 0;
	if (MINUS == '1')
		ZERO = '0';
	if (p->prec > len)
		size = p->prec - len;
	ft_arg_mal(s, len + size, p);
	push_arg_hex_oct(s, tmp, len, p);
	printf("%s| - s\n", *s);
	// if (ZERO == '1' && MINUS == '1')
	// 	ZERO = '0';
	// if (PLUS == '1')
	// 	s = form_plus(s);
	// else if (SPACE == '1')
	// 	s = form_space(s);
	// if (p->width > (int)ft_strlen(s))
	// 	s = form_width_minus(s, p);
}
