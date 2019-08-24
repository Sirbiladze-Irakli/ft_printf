/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:13:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 16:23:28 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    struct_init(t_printf *p)
{
    ft_memset(p->flags, '0', 5);
	p->width = 0;
	p->prec = -1;
	ft_bzero(p->modifier, 4);
	p->specifier = '\0';
}