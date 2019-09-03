/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:08:43 by brickon-          #+#    #+#             */
/*   Updated: 2019/09/03 18:20:01 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// void	ft_create_struct(t_printf *p)
// {
// 	p->minus = 0;
// 	p->plus = 0;
// 	p->pres = -1;
// 	p->space = 0;
// 	p->wh = 0;
// 	ZERO = 0';'
// }

char	*ft_str_write_push(char *dest, char *src, int push)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i + push] = src[i];
		i++;
	}
	return (dest);
}

void	ft_pars_width_float2(char **s, t_printf *p, char **str)
{
	*str = ft_str_write_push(*str, *s, p->width - ft_strlen(*s));
	if (SPACE == '1')
		(*str)[p->width - ft_strlen(*s) - 1] = ' ';
	if (PLUS == '1' && ZERO == '1')
		(*str)[0] = '+';
	if (PLUS == '1' && ZERO == '0')
		(*str)[p->width - ft_strlen(*s) - 1] = '+';
	if (p->sig == '-' && ZERO == '1')
		(*str)[0] = '-';
	if (p->sig == '-' && ZERO == '0')
		(*str)[p->width - ft_strlen(*s) - 1] = '-';
}

char	*ft_pars_width_float(char **s, t_printf *p)
{
	char *str;

	str = ft_strnew(p->width);
	if (ZERO == '1')
		str = ft_memset(str, '0', p->width);
	else
		str = ft_memset(str, ' ', p->width);
	if (MINUS == '1')
	{
		if (p->sig == '-' || PLUS == '1' || SPACE == '1')
			str = ft_str_write_push(str, *s, 1);
		else
			str = ft_str_write_push(str, *s, 0);
		if (SPACE == '1')
			str[0] = ' ';
		if (PLUS == '1')
			str[0] = '+';
		if (p->sig == '-')
			str[0] = '-';
	}
	else if (MINUS == '0')
		ft_pars_width_float2(s, p, &str);
	free(*s);
	*s = str;
	return (str);
}

void	ft_space_zero_float(char **s, t_printf *p)
{
	char *str;

	if (p->width <= (int)ft_strlen(*s))
	{
		str = ft_strnew(ft_strlen(*s) + 1);
		if (SPACE != '1' && PLUS != '1' && p->sig != '-')
			str = ft_str_write_push(str, *s, 0);
		else
			str = ft_str_write_push(str, *s, 1);
		if (SPACE == '1')
			str[0] = ' ';
		if (PLUS == '1')
			str[0] = '+';
		if (p->sig == '-')
			str[0] = '-';
		free(*s);
		*s = str;
	}
	else
		str = ft_pars_width_float(s, p);
	free(*s);
	*s = str;
}
