/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:16:42 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 14:27:54 by jormond-         ###   ########.fr       */
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

void    ft_strdup_free(char **s, char *arg, t_printf *p)
{
    char    *tmp;

    tmp = ft_strdup(arg);
    *s = tmp;
    free(tmp);
}

void    ft_push_arg(char **s, char *tmp, t_printf *p)
{
    int     i;
    int     len;
    int     size;

    i = -1;
    len = ft_strlen(tmp);
    size = ft_size_modif(len, p);
    ft_push_arg2(s, tmp, size, p);
}

void    ft_push_arg2(char **s, char *tmp, int size, t_printf *p)
{
    int     i;
    int     len;

    i = -1;
    len = ft_strlen(tmp);
    if (p->prec == 0)
        return ;
    else if (p->prec > 0 && p->prec < len)
        while(++i < p->prec)
            (*s)[size + i] = tmp[i];
    else
        while(tmp[++i])
            (*s)[size + i] = tmp[i];
}

void    ft_write_arg(char *s, int len, t_printf *p)
{
    if (p->width < len && (p->prec < 0 || p->prec > len))
        write(1, s, len);
    else if (p->width < len && p->prec > 0 && p->prec < len)
        write(1, s, p->prec);
    else
        write(1, s, p->width);
}



int     ft_size_modif(int len, t_printf *p)
{
    int     res;

    if (MINUS == '1')
        res = 0;
    else if ((p->width - len) > 0 && p->prec == -1)
        res = p->width - len;
    else if (p->width > len && p->prec > 0 && p->prec < len)
        res = p->width - p->prec;
    else
        res = p->width - len;
    if (res < 0)
        res = 0;
    return (res);
}