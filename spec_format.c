/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:24:07 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/21 15:16:35 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    format_str(char *s, char *buf)
{
    int     i;
    int     minus;
    char    width[11];
	char	prec[11];

	minus = 0;
	ft_bzero(width, 11);
	ft_bzero(prec, 11);
	printf("%s", buf);
    while(*buf)
    {
		i = 0;
        if (*buf == '-')
			minus = 1;
		if (ft_strchr("123456789", *buf) && (!*buf - 1 || *buf - 1 != '.'))
			while(ft_strchr("123456789", *buf))
                width[i++] = *buf++;
		i = 0;
		if (*buf++ == '.')
			while(ft_strchr("123456789", *buf))
				prec[i++] = *buf++;
	}
	form_width_minus(s, width, minus);
}