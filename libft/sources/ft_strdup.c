/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:15:52 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:27:35 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char *copy;

	if (!(copy = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	ft_strcpy(copy, (char *)str);
	return (copy);
}
