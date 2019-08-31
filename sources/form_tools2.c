/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:47:47 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/31 18:19:29 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    push_arg_hex_oct(char **s, char *tmp, int len, t_printf *p)
{
	int		i;
    int     calibr;

	i = -1;
	calibr = calibration_of_prec(len, p);
    if (HASH == '1' && p->specifier == 'p')
	{
		push_hash(s, calibr, len, p);
		calibr += 2;
	}
	calibr = push_zero(s, calibr, len, p);
	if (p->width > len && p->width > p->prec && ZERO == '1'
		&& MINUS == '1')
		cut_zero(s, len, p);
	while(tmp[++i])
		(*s)[calibr + i] = tmp[i];
}

void	push_hash(char **s, int calibr, int len, t_printf *p)
{
    int     i;

    char    *hash;

    i = -1;
    hash = whats_hash(p);
	while(++i < 2)
		(*s)[calibr + i] = hash[i];
}

char	*whats_hash(t_printf *p)
{
	char	*tmp;

	if (p->specifier == 'x' || p->specifier == 'p')
		tmp = "0x";
	else
		tmp = "0X";
	return (tmp);
}

int		calibration_of_prec(int len, t_printf *p)
{
	int		res;
	int		tmp;

	if (len > p->prec)
		tmp = len + 2;
	else
		tmp = p->prec + 2;
	if (MINUS == '1' || p->width <= len + 2 || p->width <= p->prec + 2
		|| ZERO == '1')
		res = 0;
	else if (p->width >= tmp)
		res = p->width - tmp;
	return (res);
}

