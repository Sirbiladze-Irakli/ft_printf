/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/03 19:05:30 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			distributor(va_list ap, char *buf, t_printf *p)
{
	int res;
	int  buf_size;

	res = 0;
	buf_size = ft_strlen(buf) + 1;
	if (ft_strchr("di", p->specifier))
		res = sort_int(ap, buf_size, p);
	else if (p->specifier == 'c')
		res = sort_chr(ap, buf_size, p);
	else if (p->specifier == 'p')
	    res = sort_ptr(ap, buf_size, p);
	else if (p->specifier == 's')
		res = sort_str(ap, buf_size, p);
	else if (ft_strchr("xX", p->specifier))
		res = sort_hex(ap, buf_size, p);
	else if (p->specifier == 'o')
		res = sort_oct(ap, buf_size, p);
	else if (p->specifier == 'b')
		res = sort_bin(p->specifier, buf_size, ap);
	else if (p->specifier == 'u')
		res = sort_uint(ap, buf_size, p);
	else if (p->specifier == '%')
		res = sort_per(p, buf_size);
	else if (p->specifier == 'f')
		res = sort_float(ap, buf_size, p);
	return (res);
}

int     ft_arg_reader(const char *format, int i, va_list ap)
{
	char		buf[BUFF_SIZE];
	t_printf	p;
	int			j;

	j = 0;
	ft_bzero(buf, BUFF_SIZE);
	while (format[++i])
	{
		buf[j++] = format[i];
		if (ft_strchr("bcspdiouxXf%", format[i]))
		{
			buf[j] = '\0';
			parse_struct(buf, &p);
			j = distributor(ap, buf, &p);
			return (j);
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int	        i;
	static int	ret;
	va_list     ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while(format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			write(1, "\n", 1);
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			ret += ft_arg_reader(format, i, ap);
			while(!(ft_strchr("bcspdiouxXf%", format[++i])))
				;
		}
		i++;
		
	}
	ret += i;
	va_end(ap);
	return (ret);
}