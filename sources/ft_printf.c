/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 12:03:30 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		distributor(va_list ap, t_printf *p)
{
    if (ft_strchr("diuc", p->specifier))
        sort_int_chr(p->specifier, ap, p);
    else if (p->specifier == 's' || p->specifier == 'p')
        sort_str_ptr(p->specifier, ap, p);
    else if (ft_strchr("oxX", p->specifier))
        sort_oct_hex(p->specifier, ap, p);
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