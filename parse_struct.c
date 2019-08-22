/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:04:00 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/22 18:05:28 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    parse_struct(char *buf, t_printf *p)
{
	int	i;

	i = 0;
    struct_init(p);
    while (buf[i++])
    {
		if (buf[i] == '-')
			MINUS = '1';
		if (buf[i] == '0')
			ZERO = '1';
		if (buf[i] == '+')
			PLUS = '1';
		if (buf[i] == '#')
			HASH = '1';
		if (buf[i] == ' ')
			SPACE = '1';
		if (ft_strchr("123456789", buf[i]) && buf[i - 1] != '.')
        	i = width_converter(p, buf, i);
		if (ft_strchr("123456789", buf[i]) && buf[i - 1] == '.')
        	i = prec_converter(p, buf, i);
		if (ft_strchr("hlL", buf[i]))
			i = modif_checker(p, buf, i);
	}
	// printf("%s - flags\n%d - w\n %d - p\n %s - mod", p->flags, p->width, p->prec, p->modifier);
}