/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:00:11 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/02 12:29:15 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     fill_plus_or_space(char **s, int calibr, t_printf *p)
{
    if (PLUS == '1')
        (*s)[calibr] = '+';
    else if (PLUS == '0' && SPACE == '1')
        (*s)[calibr] = ' ';
    return (++calibr);
}

int		cut_front_zero(char **s, t_printf *p)
{
	int 	i;
	int		size;

	i = -1;
	size = p->width - p->prec;
	while(++i < size)
		(*s)[i] = ' ';
	return(i);
}