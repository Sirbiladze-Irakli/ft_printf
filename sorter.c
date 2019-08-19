/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/19 19:47:57 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    sort_int_arg(char c, va_list ap)
{
    int     i;
    char    *my_int;

    my_int = ft_strnew(11);
    if(ft_strchr("di", c))
    {
        my_int = ft_itoa(i = va_arg(ap, int));
        write(1, my_int, ft_strlen(my_int));
    }
    if(c == 'c')
    {
        c = va_arg(ap, int);
        write(1, &c, 1);
    }
}

void	sort_str_ptr(char c, va_list ap)
{
    void			*ptr;
	char			*s;

	s = ft_strnew(BUFF_SIZE);
	if(c == 's')
	{
		s = va_arg(ap, char *);
		write(1, s, ft_strlen(s));
	}
	if(c == 'p')
	{
		ptr = va_arg(ap, void *);
		s = ft_itoa_base_c((unsigned long long)ptr, 16, c);
		write(1, "0x", 2);
		write(1, s, ft_strlen(s));
	}
}

void	sort_oct_hex(char c, va_list ap)
{
	unsigned long	i;
	char			*s;

	s = ft_strnew(BUFF_SIZE);
	if (c == 'x' || c == 'X')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 16, c);
		write(1, s, ft_strlen(s));
	}
	if (c == 'o')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 8, c);
		write(1, s, ft_strlen(s));
	}
}

