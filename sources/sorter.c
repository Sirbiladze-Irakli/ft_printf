/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 18:36:24 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    sort_int(va_list ap, t_printf *p)
{
	char    *s;

	if(p->specifier == 'd' || p->specifier == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		s = format_int(s, p);
		write(1, s, ft_strlen(s));
	}
	if(p->specifier == 'u')
	{
		s = ft_itoa(va_arg(ap, unsigned long));
		write(1, s, ft_strlen(s));
	}
	free (s);
}

void    sort_chr(va_list ap, t_printf *p)
{
	char	c1;
	char    *s;
	int		len;

	len = 1;
	c1 = va_arg(ap, int);
	format_chr(&s, p, c1);
	if (MINUS == '1' || p->width == 0)
		s[0] = c1;
	else
		s[p->width - len] = c1;
	ft_write_arg_c(s, len, p);
	free (s);
}

void	sort_str(va_list ap, t_printf *p)
{
	char	*s;
	char	*tmp;
	int		len;

	tmp = va_arg(ap, char *);
	len = ft_strlen(tmp);
	format_str(&s, tmp, len, p);
	ft_write_arg(s, len, p);
	free (s);
}

void	sort_ptr(va_list ap, t_printf *p)
{
    void	*ptr;
	char	*tmp;
	char	*s;
	int		len;

	ptr = va_arg(ap, void *);
	tmp = ft_itoa_base_c((unsigned long long)ptr, 16, p->specifier);
	len = ft_strlen(tmp) + 2;
	format_ptr(&s, tmp, len, p);
	// ft_write_arg(s, len, p);
	free (s);
}

void	sort_oct_hex(va_list ap, t_printf *p)
{
	unsigned long	i;
	char			*s;

	if (p->specifier == 'x' || p->specifier == 'X')
	{
		i = va_arg(ap, unsigned long);
		s = ft_strnew(ft_nbrlen(i));
		s = ft_itoa_base_c(i, 16, p->specifier);
		s = format_hex(s, p);
		write(1, s, ft_strlen(s));
	}
	if (p->specifier == 'o')
	{
		i = va_arg(ap, unsigned long);
		s = ft_strnew(ft_nbrlen(i));
		s = ft_itoa_base_c(i, 8, p->specifier);
		s = format_oct(s, p);
		write(1, s, ft_strlen(s));
	}
}