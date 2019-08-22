/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/22 20:07:02 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    sort_int_arg(char c, va_list ap, char *buf)
{
    int     i;
    char    *s;

    s = ft_strnew(11);
    if(ft_strchr("di", c))
    {
        s = ft_itoa(i = va_arg(ap, int));
		
        write(1, s, ft_strlen(s));
    }
    if(c == 'c')
    {
        *s = (c = va_arg(ap, int));
        write(1, s, 1);
    }
}

void	sort_str_ptr(char c, va_list ap, char *buf, t_printf *p)
{
    void			*ptr;
	char			*s;
	int				d;

	if(c == 's')
	{
		s = ft_strnew(ft_strlen(va_arg(ap, char *)));
		// printf("%s", s);
		format_str(s, p);
		// write(1, s, ft_strlen(s));
	}
	if(c == 'p')
	{
		ptr = va_arg(ap, void *);
		s = ft_itoa_base_c((unsigned long long)ptr, 16, c);
		write(1, "0x", 2);
		write(1, s, ft_strlen(s));
	}
}

void	sort_oct_hex(char c, va_list ap, char *buf)
{
	unsigned long	i;
	char			*s;

	s = ft_strnew(BUFF_SIZE);
	if (c == 'x' || c == 'X')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 16, c);
		write(1, "0x", 2);
		write(1, s, ft_strlen(s));
	}
	if (c == 'o')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 8, c);
		write(1, "0", 1);
		write(1, s, ft_strlen(s));
	}
}

