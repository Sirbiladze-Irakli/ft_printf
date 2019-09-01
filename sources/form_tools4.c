/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:00:11 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/01 16:53:16 by jormond-         ###   ########.fr       */
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