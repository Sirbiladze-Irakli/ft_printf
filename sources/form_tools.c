/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 18:33:33 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    form_prec_min(char **s, char *tmp, t_printf *p)
{
	if (p->prec < 0 && p->dot == 0)
		return ;
	else if (p->prec >= 0)
	{
		// ft_strcut_arg(tmp, p);
		return ;
	}
	else
	{
		p->prec = 6;

	}
	
}

// void	form_width_char(char **s, int len, char c1, t_printf *p)
// {
// 	ft_arg_malloc(s, len, p);
// }

// void    form_width(char **s, int len, char *tmp, t_printf *p)
// {
// 	ft_arg_malloc(s, len, p);
// }

void	ft_arg_mal(char **s, int len, t_printf *p)
{
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
}

void	form_zero(char **s, int size, t_printf *p)
{
	if (ZERO == '1')
		*s = ft_memset(*s, 48, size);
	else
		*s = ft_memset(*s, 32, size);
}

int		ft_size_mal(int len, t_printf *p)
{
	int		res;

	p->prec < len ? p->prec = -1 : p->prec;
	if (len > p->prec && len > p->width)
		res = len;
	else if (p->prec > p->width && p->prec > len)
		res = p->prec + 2;
	else if ((p->width > len) && (p->width > p->prec + 2))
		res = p->width;
	else if (len > p->prec)
		res = len;
	else
		res = p->prec + 2;
	return (res);
}