/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:33:25 by rage              #+#    #+#             */
/*   Updated: 2019/08/21 22:48:22 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     width_converter(char *buf, int i)
{
	int		j;
    char	tmp[11];

	j = 0;
	while(ft_strchr("0123456789", buf[i]))
		tmp[j++] = buf[i++];
	tmp[j] = '\0';
	return(ft_atoi(tmp));
}