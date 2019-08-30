/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 14:52:30 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    sort_int_chr(char c, va_list ap, t_printf *p)
{
	int		len;
	char    *s;
	char	c1;

	len = 1;
	if(c == 'd' || c == 'i')
		{
		    s = ft_itoa(va_arg(ap, int));
			s = format_int(s, p);
		    write(1, s, ft_strlen(s));
		}
    if(c == 'c')
    {
		printf("sss");
        c1 = va_arg(ap, int);
		format_chr(&s, p, c1);
		ft_write_arg(s, len, p);
    }
	if(c == 'u')
    {
		s = ft_itoa(va_arg(ap, unsigned long));
        write(1, s, ft_strlen(s));
    }
	free (s);
}

void	sort_str_ptr(char c, va_list ap, t_printf *p)
{
    void	*ptr;
	char	*s;
	char	*tmp;
	int		len;

	if(c == 's')
	{
		tmp = va_arg(ap, char *);
		len = ft_strlen(tmp);
		format_str(&s, tmp, len, p);
		ft_write_arg(s, len, p);
	}
	// if(c == 'p')
	// {
	// 	ptr = va_arg(ap, void *);
	// 	s = ft_itoa_base_c((unsigned long long)ptr, 16, c);
	// 	s = format_ptr(s, p);
	// 	write(1, s, ft_strlen(s));
	// }
	free (s);
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