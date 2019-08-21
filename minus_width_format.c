/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_width_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:32:24 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/21 15:06:23 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    form_width_minus(char *s, char *width, int minus)
{
    int     size;
    char    *s1;

    size = ft_atoi(width) - ft_strlen(s);
    printf("%d\n", size);
}