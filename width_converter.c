/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:33:25 by rage              #+#    #+#             */
/*   Updated: 2019/08/22 16:39:48 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     width_converter(t_printf *p, char *buf, int i)
{
	int		j;
    char	tmp[11];

	j = 0;
	while(ft_strchr("0123456789", buf[i]))
		tmp[j++] = buf[i++];
	tmp[j] = '\0';
	p->width = ft_atoi(tmp);
	return(i);
}