/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:13:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/21 18:15:06 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    struct_init(t_printf *p)
{
    ft_bzero(p->flags, 5);
	p->width = 0;
	p->prec = 0;
	ft_bzero(p->modifier, 4);
	p->specifier = '\0';
}