/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:13:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/23 20:05:47 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    struct_init(t_printf *p)
{
    ft_memset(p->flags, '0', 5);
	p->width = 0;
	p->prec = 0;
	ft_bzero(p->modifier, 4);
	p->specifier = '\0';
}