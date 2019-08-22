/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_width_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:32:24 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/22 20:44:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    form_width_minus(char *s, t_printf *p)
{
    int     size;
    char    *s1;

    size = 0;
    if (p->width > ft_strlen(s))
        size = p->width - ft_strlen(s);
    if (size > 0)
    {
        s1 = ft_strnew(size);
        s1 = ft_memset(s1, 32, size);
        // if (MINUS == 1)
        //     ft_join_free(&s, s1);
        // else
        s = ft_strjoin(s, s1);
        free(s1);
    }
    printf("%s\n", s1);
}