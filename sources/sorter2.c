/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:18:31 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/03 19:06:31 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sort_bin(char c, int  buf_size, va_list ap)  // make with bytes operators
{
	unsigned long	i;
	char			*s;
	int				len;

	s = ft_strnew(BUFF_SIZE);
	i = va_arg(ap, unsigned long);
	s = ft_itoa_base_c(i, 2, c);
	len = ft_strlen(s);
	write(1, s, len);
	return (len - buf_size);
}

int		sort_oct(va_list ap, int  buf_size, t_printf *p)
{
	unsigned long long	arg;
	char				*tmp;
	char				*s;
	int					len;

	arg = va_arg(ap, unsigned long);
	var_unsign_modif(&arg, p);
	tmp = ft_itoa_base_c(arg, 8, p->specifier);
	len = ft_strlen(tmp);
	if (HASH == '1')
		len++;
	len = format_oct(&s, tmp, len, p);
	write(1, s, len);
	free (s);
	return (len - buf_size);
}

int		sort_uint(va_list ap, int  buf_size, t_printf *p)
{
	unsigned long long	arg;
	int					len;
	char    			*s;
	char				*tmp;

	HASH = '0';
	SPACE = '0';
	PLUS = '0';
	arg = va_arg(ap, unsigned long);
	var_unsign_modif(&arg, p);
	tmp = ft_itoa(arg);
	len = ft_strlen(tmp);
	format_int(&s, tmp, len, p);
	free (tmp);
	len = write_arg_int(len, p);
	write (1, s, len);
	free (s);
	return (p->width > len ? p->width - buf_size : len - buf_size);
}

int		sort_per(t_printf *p, int  buf_size)
{
	int		len;
	char    *s;

	len = 1;
	p->prec = 0;
	format_per(&s, p);
	if (p->width > len)
		len = p->width;
	write(1, s, len);
	free (s);
	return (len - buf_size);
}

int		sort_float(va_list ap, int  buf_size, t_printf *p)
{
	// char	*s;
	double	arg;

	buf_size = 1;
	p->width = 1;
	arg = va_arg(ap, double);
	// s = ft_conv_float(arg, p, 1);
	return (buf_size);
}