/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_hex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:06:00 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 16:07:37 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*form_join_zero(char *s1, t_printf *p, int size)
{
	int		i;

	i = -1;
	while (++i < (p->prec) - size)
        s1[i] = '0';
    return (s1);
}

char	*form_check_hash(char *s1, t_printf *p)
{
	if (HASH == '1' && p->specifier == 'x')
        s1 = ft_strjoin("0x", s1);
    else if (HASH == '1' && p->specifier == 'X')
        s1 = ft_strjoin("0X", s1);
    return (s1);
}

char	*form_wd_zero(char *s1, t_printf *p)
{
	int		i;
    int     size;

    size = p->width - p->prec;
	i = -1;
	while (++i < size)
        s1[i] = ' ';
    return (s1);
}

void    form_wd_check_hash(char *s1, t_printf *p)
{
    int     i;
    char    *h;

    i = -1;
    if (p->specifier == 'x')
        h = "0x";
    else
        h = "0X";
    while(h[++i])
        s1[i] = h[i];
}

char    *form_zero_hash(char *s, char *s1, t_printf *p)
{
    int     i;
    int     j;
    int     size;
    char    *h;

    i = -1;
    j = 0;
    if ((size = p->width - (int)ft_strlen(s)) < 0)
        size = 0;
    if (HASH == '1' && ZERO == '0')
    {
		if (p->specifier == 'x')
    	    h = "0x";
    	else
    	    h = "0X";
    	while(h[++i])
    	    s1[size - 2 + i] = h[i];
	}
    else if (HASH == '1')
    {
		form_wd_check_hash(s1, p);
        
    }
    i = -1;
    while(s[j])
        s1[size + ++i] = s[j++];
    return (s1);
}