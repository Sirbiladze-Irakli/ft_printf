/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/01 13:42:25 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		distributor(va_list ap, t_printf *p)
{
	if (ft_strchr("di", p->specifier))
		sort_int(ap, p);
	else if (p->specifier == 'c')
		sort_chr(ap, p);
	else if (p->specifier == 'p')
	    sort_ptr(ap, p);
	else if (p->specifier == 's')
		sort_str(ap, p);
	else if (ft_strchr("xX", p->specifier))
		sort_hex(ap, p);
	else if (p->specifier == 'o')
		sort_oct(ap, p);
	else if (p->specifier == 'b')
		sort_bin(p->specifier, ap);
	else if (ft_strchr("%%", p->specifier))
		write(1, "%%", 1);
}

int     ft_arg_reader(const char *format, int i, va_list ap)
{
	char		buf[BUFF_SIZE];
	t_printf	p;
	int			j;

	j = 0;
	ft_bzero(buf, BUFF_SIZE);
	while (format[i])
	{
		buf[j++] = format[i++];
		if (ft_strchr("bcspdiouxXf", format[i - 1]))
		{
			buf[j] = '\0';
			parse_struct(buf, &p);
			distributor(ap, &p);
			return (--i);
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int	        i;
	va_list     ap;

	i = 0;
	va_start(ap, format);
	while(format[i] != '\0')
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
			i = ft_arg_reader(format, i, ap);
		i++;
	}    
	va_end(ap);
	return (i);
}