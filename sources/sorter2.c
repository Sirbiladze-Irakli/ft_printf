/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:18:31 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/02 12:52:38 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sort_bin(char c, va_list ap)
{
	unsigned long	i;
	char			*s;

	s = ft_strnew(BUFF_SIZE);
	if (c == 'b')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 2, c);
		write(1, s, ft_strlen(s));
	}
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

void	sort_uint(va_list ap, t_printf *p)
{
	int		len;
	char    *s;
	char	*tmp;

	HASH = '0';
	SPACE = '0';
	PLUS = '0';
	tmp = ft_itoa(va_arg(ap, unsigned long));
	len = ft_strlen(tmp);
	format_int(&s, tmp, len, p);
	write_arg_int(s, len, p);
	free (s);
}