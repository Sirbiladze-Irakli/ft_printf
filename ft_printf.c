/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/22 20:07:05 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		distributor(char *buf, va_list ap, t_printf *p)
{
	int i;

	i = 0;
    while(buf[i])
    {
		if (ft_strchr("cdi", buf[i]))
			sort_int_arg(buf[i], ap, buf);
        if (ft_strchr("sp", buf[i]))
			sort_str_ptr(buf[i], ap, buf, p);
        if (ft_strchr("oxX", buf[i]))
			sort_oct_hex(buf[i], ap, buf);
        if (ft_strchr("b", buf[i]))
			sort_bin(buf[i], ap);
        if (ft_strchr("%%", buf[i]))
			write(1, "%%", 1);
		i++;
    }
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
        buf[j++] = format[i];
        if (ft_strchr("bcspdiouxXf", format[i]))
        {
			buf[j] = '\0';
			parse_struct(buf, &p);
            distributor(buf, ap, &p);

			j = 0;
        }
		i++;
    }
    return (i);
}

static int		ft_printf(const char *format, ...)
{
    int	        i;
    va_list     ap;

    i = 0;
    va_start(ap, format);
    while(format[i])
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

int     main()
{
	// long int c = 123412343;
    // long double   a = 123.123;
    // int     a[4] = {1, 2, 3, 4};
	// char    b = 8;
	// char    c = ~b + 1;
	
	// printf("% 06d\n", 45);
    ft_printf("%4s\n", "hi");
    // printf("Raspberry Pi %d%%\n", 3);
	// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");
    // printf("%c\n", 'g');

    // printf("%-6.4s\n", "Irakli");
	// printf("%3c\n", 'c');
	// printf("%lld\n", 52);
	// printf("%i\n", 2047);
	// printf("%Lo\n", c);
	// printf("%20Lx\n", 1024);
	// printf("%Lp\n", &c);
	// printf("%+%");
	// printf("%Lf\n", a);
	
    // printf("%p\n", "wefwv");
	// printf("%5. 6. 4d\n", 2);
    return (0);
}