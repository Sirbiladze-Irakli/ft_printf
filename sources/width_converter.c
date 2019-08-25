/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:33:25 by rage              #+#    #+#             */
/*   Updated: 2019/08/24 18:04:12 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     width_converter(t_printf *p, char *buf, int i)
{
	int		j;
    char	tmp[11];

	j = 0;
	while(ft_compare_chr("0123456789", buf[i]))
		tmp[j++] = buf[i++];
	tmp[j] = '\0';
	p->width = ft_atoi(tmp);
	return(i);
}