/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:17:36 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    sort_int_chr(char c, va_list ap, t_printf *p)
{
	char    *s;

	s = ft_strnew(11);
	if(c == 'd' || c == 'i')
		{
		    s = ft_itoa(va_arg(ap, int));
			s = format_int(s, p);
		    write(1, s, ft_strlen(s));
		}
    if(c == 'c')
    {
        s[0] = (c = va_arg(ap, int));
		s = format_chr(s, p);
        write(1, s, ft_strlen(s));
    }
	if(c == 'u')
    {
		s = ft_itoa(va_arg(ap, unsigned long));
		s = format_uint(s, p);
        write(1, s, ft_strlen(s));
    }
}

void	sort_str_ptr(char c, va_list ap, t_printf *p)
{
    void			*ptr;
	char			*s;

	s = ft_strnew(4096);
	if(c == 's')
	{
		s = va_arg(ap, char *);
		s = format_str(s, p);
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

void	sort_oct_hex(char c, va_list ap, t_printf *p)
{
	unsigned long	i;
	char			*s;

	s = ft_strnew(BUFF_SIZE);
	if (c == 'x' || c == 'X')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 16, c);
		if (HASH == '1')
			write(1, "0x", 2);
		write(1, s, ft_strlen(s));
	}
	if (c == 'o')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 8, c);
		if (HASH == '1')
			write(1, "0", 1);
		write(1, s, ft_strlen(s));
	}
}

