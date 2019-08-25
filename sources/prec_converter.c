/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:36:13 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:03:42 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int    prec_converter(t_printf *p, char *buf, int i)
{
    int		j;
    char	tmp[11];
    
    j = 0;
	if (!ft_compare_chr("0123456789", buf[i]))
		p->prec = 0;
	else
	{
		while(ft_compare_chr("0123456789", buf[i]))
			tmp[j++] = buf[i++];
		tmp[j] = '\0';
		p->prec = ft_atoi(tmp);
	}
	return(i);
}