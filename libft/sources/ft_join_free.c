/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:46:54 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:25:56 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_join_free(char **content, char *buf)
{
	char	*tmp;

	tmp = *content;
	tmp = ft_strjoin(*content, buf);
	free(*content);
	*content = tmp;
}
