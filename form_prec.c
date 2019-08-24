/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 15:48:29 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *form_prec(char *s, t_printf *p)
{
	int		i;
	char	*s1;

	i = -1;
	s1 = ft_strnew(ft_strlen(s));
	while(++i < p->prec)
		s1[i] = s[i];
    return (s1);
}