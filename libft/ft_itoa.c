/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:55:02 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 16:01:42 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_uintlen(unsigned int n)
{
	size_t	size;

	size = 0;
	while (n >= 10 ? n /= 10 : 0)
		++size;
	return (++size);
}

char	*ft_itoa(long int n)
{
	char			*str;
	unsigned int	un;
	long int		i;
	size_t			size;

	un = n < 0 ? (unsigned int)(n * -1) : (unsigned int)n;
	size = ft_uintlen(un);
	if ((str = ft_strnew(size + (n < 0 ? 1 : 0))))
	{
		n < 0 && (str[0] = '-') ? (++size) : 0;
		i = (int)(size - 1);
		while (un > 9)
		{
			str[i--] = (char)(un % 10 + '0');
			un /= 10;
		}
		str[i] = (char)(un % 10 + '0');
		str[size] = '\0';
	}
	return (str);
}