/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:02:55 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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