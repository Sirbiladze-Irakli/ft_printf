/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:19:52 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/21 22:54:21 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    parse_struct(char *buf, t_printf *p)
{
	int	i;

	i = 0;
    struct_init(p);
    while (ft_strchr("bcspdiouxXf", buf[i++]))
    {
		printf("%d - i\n", i);
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
		if (ft_strchr("123456789", buf[i]) && buf[i] - 1 != '.')
        	p->width = width_converter(buf, i);
		printf("%d -  p->width\n", p->width);
	}
}