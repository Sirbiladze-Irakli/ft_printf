/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:05:58 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/22 18:07:09 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     modif_checker(t_printf *p, char *buf, int i)
{
    int     j;

    j = 0;
    while(ft_strchr("hlL", buf[i]))
        p->modifier[j++] = buf[i++];
    p->modifier[j] = '\0';
    return(i);
}