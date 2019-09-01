/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/01 17:00:01 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    sort_int(va_list ap, t_printf *p)
{
	int		len;
	char    *s;
	char	*tmp;

	HASH = '0';
	tmp = ft_itoa(va_arg(ap, long long));
	len = ft_strlen(tmp);
	if (PLUS == '1' || SPACE == '1')
	{
		if (p->width == len || p->width == p->prec)
			p->width++;
		len++;
		p->prec++;
		
	}
	if (PLUS == '1' && SPACE == '1')
		SPACE = '0';
	format_int(&s, tmp, len, p);
	write_arg(s, len, p);
	// if(p->specifier == 'u')
	// {
	// 	s = ft_itoa(va_arg(ap, unsigned long));
	// 	write(1, s, ft_strlen(s));
	// }
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
	write_arg_c(s, len, p);
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
	write_arg(s, len, p);
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
	p->prec += 2;
	format_ptr(&s, tmp, len, p);
	free (s);
}

void	sort_hex(va_list ap, t_printf *p)
{
	unsigned long	i;
	char			*tmp;
	char			*s;
	int				len;

	i = va_arg(ap, unsigned long);
	tmp = ft_itoa_base_c(i, 16, p->specifier);
	len = ft_strlen(tmp);
	if (HASH == '1')
	{
		len += 2;
		p->prec += 2;
	}
	format_hex(&s, tmp, len, p);
	free (s);
}

void	sort_oct(va_list ap, t_printf *p)
{
	unsigned long	i;
	char			*tmp;
	char			*s;
	int				len;

	i = va_arg(ap, unsigned long);
	tmp = ft_itoa_base_c(i, 8, p->specifier);
	len = ft_strlen(tmp);
	if (HASH == '1')
		len++;
	format_oct(&s, tmp, len, p);
	free (s);
}