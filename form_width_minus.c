/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_width_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:32:24 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 17:21:09 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *form_width_minus(char *s, t_printf *p)
{
    int     i;
    int     size;
    char    *s1;

    i = -1;
    size = p->width - ft_strlen(s);
    s1 = ft_strnew(p->width);
    if (ZERO == '1')
        s1 = ft_memset(s1, 48, p->width);
    else
        s1 = ft_memset(s1, 32, p->width);
    if (MINUS == '1')
        while(++i < ft_strlen(s))
            s1[i] = s[i];
    else
        while(s1[++i + size])
            s1[i + size] = s[i];
    return (s1);
}