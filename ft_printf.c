/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/19 23:02:04 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		distributor(char *buf, va_list ap)
{
	int i;

	i = 0;
    while(buf[i])
    {
        if (ft_strchr(" 0#+-", *buf))
			;
		if (ft_strchr("cdi", *buf))
			sort_int_arg(*buf, ap);
        if (ft_strchr("sp", *buf))
			sort_str_ptr(*buf, ap);
        if (ft_strchr("oxX", *buf))
			sort_oct_hex(*buf, ap);
        if (ft_strchr("b", *buf))
			sort_bin(*buf, ap);
        if (ft_strchr("%%", *buf));
			write(1, "%%", 1);
		i++;
    }
}

static int     ft_arg_reader(const char *format, int i, va_list ap)
{
    char    buf[BUFF_SIZE];
    int     j;

    j = 0;
    ft_bzero(buf, BUFF_SIZE);
    while (format[i++])
    {
        buf[j++] = format[i];
        if (ft_strchr("bcspdiouxXf", format[i]))
        {
            distributor(buf, ap);
            break ;
        }
    }
    return (i);
}

static int		ft_printf(const char *format, ...)
{
    int	    i;
    char    c;
    char    buf[BUFF_SIZE];
    va_list ap;

    i = 0;
    ft_bzero(buf, BUFF_SIZE);
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
	long int c = 123412343;
    float   a = 123.123;
    // int     a[4] = {1, 2, 3, 4};
	char    b = 8;
	// char    c = ~b + 1;
	
	// printf("% 06d\n", 45);
    // ft_printf("Raspberry Pi %d%%\n", 3);
    // printf("Raspberry Pi %d%%\n", 3);
	// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");
    // printf("%c\n", 'g');

    // printf("%30.3s\n", "300 - otsosi u traktorista");
	// printf("%3c\n", 'c');
	// printf("%Ld\n", c);
	// printf("%i\n", 2047);
	// printf("%Lo\n", c);
	// printf("%20Lx\n", 1024);
	// printf("%Lp\n", &c);
	// printf("%+%");
	printf("%20u\n", 1024);
	
    // printf("%p\n", "wefwv");
	// printf("%5. 6. 4d\n", 2);
    return (0);
}