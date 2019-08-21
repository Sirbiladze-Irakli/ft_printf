/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:18:31 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/21 17:25:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sort_bin(char c, va_list ap)
{
	unsigned long	i;
	char			*s;

	s = ft_strnew(BUFF_SIZE);
	if (c == 'b')
	{
		i = va_arg(ap, unsigned long);
		s = ft_itoa_base_c(i, 2, c);
		write(1, s, ft_strlen(s));
	}
}