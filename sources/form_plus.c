/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:37:03 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:02:51 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*form_plus(char *s)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = ft_strnew(ft_strlen(s)) + 1;
	if (s[i] != '-')
	{
		s1[i++] = '+';
		while(s[i - 1])
		{
			s1[i] = s[i - 1];
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			s1[i] = s[i];
			i++;
		}
	}
	return(s1);
}