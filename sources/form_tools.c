/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/28 20:11:31 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    form_prec_min(char **s, char *tmp, t_printf *p)
{
	if (p->prec < 0 && p->dot == 0)
		return ;
	else if (p->prec >= 0)
	{
		ft_strsub_free(s, tmp, p);
		return ;
	}
	else
	{
		p->prec = 6;

	}
	
}

void    form_width(char **s, int len, char *tmp, t_printf *p)
{
	int		i;
	int		size;

	i = -1;
	if ((size = p->width - len) < 0)
		size = 0;
	if (p->width > len)
	{
		*s = (char *)malloc(sizeof(char) * (p->width));
		form_zero(s, p->width, p);
	}
	else
	{
		*s = (char *)malloc(sizeof(char) * (len));
		form_zero(s, len, p);
	}
	while (++i)
		s[size + i] = &tmp[i];
}

void	form_zero(char **s, int size, t_printf *p)
{
	if (ZERO == '1')
		*s = ft_memset(*s, 48, size);
	else
		*s = ft_memset(*s, 32, size);
}

// void    form_prec_max(char **s, t_printf *p)
// {
// 	char	*tmp;

// 	tmp = *s;
// 	tmp[p->prec] = '\0';
// 	*s = tmp;
// }