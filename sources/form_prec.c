/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 21:39:01 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char    *form_prec(char *s, t_printf *p)
{
	int		i;
    int     size;
	char	*s1;

	i = -1;
	size = 0;
	if (p->prec < (int)ft_strlen(s))
		s1 = ft_strnew(ft_strlen(s));
	else
	{
		s1 = ft_strnew(p->prec);
		size = p->prec - (int)ft_strlen(s);
	}
	if (size > 0)
		while (++i < size)
			s1[i] = '0';
	s1 = ft_strjoin(s1, s);
	printf("%s - s1\n", s1);
    return (s1);
}