/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:16:42 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 21:37:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_nbrlen(unsigned long i)
{
    unsigned long   tmp;
    int             counter;

    tmp = i;
    counter = 0;
    while (tmp > 0)
    {
        tmp /= 10;
        counter++;   
    }
    return (counter);
}

void    ft_strdup_free(char **s, char *arg)
{
    char    *tmp;

    tmp = *s;
    tmp = ft_strdup(arg);
    printf("%s - t\n", tmp);
    *s = tmp;
    free(tmp);
}