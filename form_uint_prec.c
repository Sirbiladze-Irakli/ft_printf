/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_uint_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:45:51 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:01:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *form_uint_prec(char *s, t_printf *p)
{
    int     i;
	int		size;
    char    *s1;

    i = 0;
	if(p->prec > (int)ft_strlen(s) && p->prec <= p->width)
	{
		s1 = ft_strnew(p->prec);
		size = p->width - (int)ft_strlen(s) - 1;
		while(i < size)
			s1[i++] = '0';
		i = -1;
		while(s[++i])
			s1[i + size] = s[i];
		return (s1);
	}
	return(s);
}