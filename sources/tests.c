/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:25:27 by rage              #+#    #+#             */
/*   Updated: 2019/08/19 19:15:35 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_itoa_base(unsigned long long value, int base)
{
    static  char		rep[] = "0123456789ABCDEF";
    static  char		buf[50];
    char				*ptr;
    unsigned long long	num;

    ptr = &buf[49];
    *ptr = '\0';
    num = value;
    if (value < 0 && base == 10)
        value *= -1;
    if (value == 0)
        *--ptr = rep[value % base];
    while (value != 0)
    {
        *--ptr = rep[value % base];
        value /= base;
    }
    if (num < 0 && base == 10)
        *--ptr = '-';
    return (ptr);
}

int     main()
{
    char *a;
    printf("%s\n", (a = ft_itoa_base(2047, 8)));
    return (0);
}