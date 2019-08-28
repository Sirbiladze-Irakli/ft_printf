/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/28 19:59:05 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    sort_int_chr(char c, va_list ap, t_printf *p)
{
	char    *s;
	char	c1;

	s = ft_strnew(11);
	if(c == 'd' || c == 'i')
		{
		    s = ft_itoa(va_arg(ap, int));
			s = format_int(s, p);
		    write(1, s, ft_strlen(s));
		}
    if(c == 'c')
    {
        c1 = (c = va_arg(ap, int));
        write(1, &c1, 1);
    }
	if(c == 'u')
    {
		s = ft_itoa(va_arg(ap, unsigned long));
        write(1, s, ft_strlen(s));
    }
}

void	sort_str_ptr(char c, va_list ap, t_printf *p)
{
    void			*ptr;
	char			*s;
	char			*tmp;
	int				i;

	i = -1;
	if(c == 's')
	{
		tmp = va_arg(ap, char *);
		if (ZERO == '1')
			ZERO = '0';
		form_width(&s, ft_strlen(tmp), tmp, p);
		while (tmp[++i])
			s[i] = tmp[i];
		format_str(&s, tmp, p);
		write(1, s, ft_strlen(s));
	}
	if(c == 'p')
	{
		ptr = va_arg(ap, void *);
		s = ft_itoa_base_c((unsigned long long)ptr, 16, c);
		s = format_ptr(s, p);
		write(1, s, ft_strlen(s));
	}
	// free (s);
}

void	sort_oct_hex(char c, va_list ap, t_printf *p)
{
	unsigned long	i;
	char			*s;

	if (c == 'x' || c == 'X')
	{
		i = va_arg(ap, unsigned long);
		s = ft_strnew(ft_nbrlen(i));
		s = ft_itoa_base_c(i, 16, c);
		s = format_hex(s, p);
		write(1, s, ft_strlen(s));
	}
	if (c == 'o')
	{
		i = va_arg(ap, unsigned long);
		s = ft_strnew(ft_nbrlen(i));
		s = ft_itoa_base_c(i, 8, c);
		s = format_oct(s, p);
		write(1, s, ft_strlen(s));
	}
}