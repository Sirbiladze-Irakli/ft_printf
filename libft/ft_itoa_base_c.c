/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:00:11 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/19 19:06:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_c(unsigned long long value, int base, char c)
{
	static char		rep[16] = "0123456789abcdef";
	static char		buf[50];
	char			*ptr;
	unsigned long	num;
	int				i;

	i = 9;
	if (c == 'X')
		while(rep[i++])
			rep[i] = ft_toupper(rep[i]);
	ptr = &buf[49];
	*ptr = '\0';
	num = value;
	if (value != 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num != 0 && base == 10)
		*--ptr = '-';
	return (ptr);
}
