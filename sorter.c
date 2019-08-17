/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/17 19:23:07 by jormond-         ###   ########.fr       */
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
	char	*s;

	s = ft_strnew(BUFF_SIZE);
	if(c == 's')
	{
		s = va_arg(ap, char *);
		write(1, s, ft_strlen(s));
	}
	if(c == 'p')
	{
		s = va_arg(ap, char *);
		
		write(1, *(&s), ft_strlen(s));
	}
}