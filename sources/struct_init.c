/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:13:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:04:04 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    struct_init(t_printf *p)
{
    ft_memset(p->flags, '0', 5);
	p->width = 0;
	p->prec = -1;
	ft_bzero(p->modifier, 4);
	p->specifier = '\0';
}