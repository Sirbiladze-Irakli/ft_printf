/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/25 19:40:27 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		distributor(char *buf, va_list ap, t_printf *p)
{
	int i;

	i = 0;
    while(buf[++i])
    {
		if (ft_strchr("diuc", buf[i]))
			sort_int_chr(buf[i], ap, p);
        else if (buf[i] == 's' || buf[i] == 'p')
			sort_str_ptr(buf[i], ap, p);
        else if (ft_strchr("oxX", buf[i]))
			sort_oct_hex(buf[i], ap, p);
        else if (buf[i] == 'b')
			sort_bin(buf[i], ap);
        else if (ft_strchr("%%", buf[i]))
			write(1, "%%", 1);
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
        buf[j++] = format[i++];
        if (ft_strchr("bcspdiouxXf", format[i - 1]))
        {
            buf[j] = '\0';
            parse_struct(buf, &p);
            distributor(buf, ap, &p);
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

int     main()
{
    unsigned int i = -423433503;
	// long int c = 123412343;
    // long double   a = 123.123;
    // int     a[4] = {1, 2, 3, 4};
	// char    b = '&';
	// char    c = ~b + 1;
	
    // printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "fasdf", "asfd");
	ft_printf("%#-050.4x - My\n", i);
    printf("%#-050.4x - Orig\n", i);
    
    // printf("%-15u\n", i);
    // printf("Raspberry Pi %d%%\n", 3);
	// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");
    // printf("%c\n", 'g');

    // printf("%-6.4s\n", "Irakli");
	// printf("%3c\n", 'c');
	// printf("%d\n", 34);
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