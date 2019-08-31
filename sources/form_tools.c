/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/31 14:19:26 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
	
	/********************************/
	/* 			cut prec			*/
	/********************************/

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

	/************************************/
	/* 		allocate memory for arg		*/
	/************************************/

void	ft_arg_mal(char **s, int len, t_printf *p)
{
	if (p->width >= len)
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

	if ((len + 2) >= p->width && (len + 2) >= (p->prec + 2))
		res = len + 2;
	if ((p->prec + 2) >= (len + 2) && (p->prec + 2) >= p->width)
		res = p->prec + 2;
	if (p->width >= (len + 2) && p->width >= (p->prec + 2))
		res = p->width;
	return (res);
}

int     ft_size_modif(int len, t_printf *p)
{
    int     res;

    if (MINUS == '1')
        res = 0;
    else if ((p->width - len) > 0 && p->prec == -1)
        res = p->width - len;
    else if (p->width > len && p->prec > 0 && p->prec < len)
        res = p->width - p->prec;
    else
        res = p->width - len;
    if (res < 0)
        res = 0;
    return (res);
}