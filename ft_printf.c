/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/18 21:06:33 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		distributor(char *buf, va_list ap)
{
	int i;

	i = 0;
    while(buf[i])
    {
        if(ft_strchr(" 0#+-", *buf))
			;
		if(ft_strchr("cdi", *buf))
			sort_int_arg(*buf, ap);
        if(ft_strchr("sp", *buf))
			sort_str_ptr(*buf, ap);
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
        if (ft_strchr("cspdiouxXf", format[i]))
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
    // int     a[4] = {1, 2, 3, 4};
	char    b = 8;
	// char    c = ~b + 1;
	
	// printf("% 06d\n", 45);
    ft_printf("Raspberry Pi %p\n", &b);
    printf("Raspberry Pi %p\n", &b);
    // printf("%c\n", 'g');
    // printf("%dhh\n", 3000);
    // printf("%p\n", "wefwv");
	// printf("%5. 6. 4d\n", 2);
    return (0);
}