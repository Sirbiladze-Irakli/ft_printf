/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/03 13:28:38 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	    sort_int(va_list ap, t_printf *p)
{
	int			len;
	long long	arg;
	char    	*s;
	char		*tmp;

	HASH = '0';
	arg = va_arg(ap, long long);
	var_sign_modif(&arg, p);
	// printf("%lld - arg\n", arg);
	if (arg < 0)
	{
		SPACE = '0';
		PLUS = '0';
	}
	tmp = ft_itoa(arg);
	len = ft_strlen(tmp);
	if ((PLUS == '1' || SPACE == '1') && arg >= 0)
		int_len_modif(&len, p);
	format_int(&s, tmp, len, p);
	free(tmp);
	len = write_arg_int(s, len, p);
	write (1, s, len);
	free (s);
	return (len);
}

int	    sort_chr(va_list ap, t_printf *p)
{
	char	c1;
	char    *s;
	int		len;

	len = 1;
	c1 = va_arg(ap, int);
	format_chr(&s, p);
	if (MINUS == '1' || p->width == 0)
		s[0] = c1;
	else
		s[p->width - len] = c1;
	len = write_arg_c(s, len, p);
	write (1, s, len);
	free (s);
	return (len);
}

int		sort_str(va_list ap, t_printf *p)
{
	char	*s;
	char	*tmp;
	int		len;

	len = 6;
	if (!(tmp = va_arg(ap, char *)))
	{
		write(1, "(null)", len);
		return (len);
	}
	else
	{
		len = ft_strlen(tmp);
		format_str(&s, tmp, len, p);
		len = write_arg(s, len, p);
		write (1, s, len);
		free (s);
	}
	return (len);
}

int		sort_ptr(va_list ap, t_printf *p)  
{
    void	*ptr;
	char	*tmp;
	char	*s;
	int		len;

	ptr = va_arg(ap, void *);
	tmp = ft_itoa_base_c((unsigned long long)ptr, 16, p->specifier);
	len = ft_strlen(tmp) + 2;
	p->prec += 2;
	len = format_ptr(&s, tmp, len, p);
	free (s);
	return (len);
}

int		sort_hex(va_list ap, t_printf *p)
{
	unsigned long long	arg;
	char				*tmp;
	char				*s;
	int					len;

	arg = va_arg(ap, unsigned long);
	var_unsign_modif(&arg, p);
	tmp = ft_itoa_base_c(arg, 16, p->specifier);
	len = ft_strlen(tmp);
	if (!ft_strcmp(tmp, "0"))
		HASH = '0';
	if (HASH == '1')
	{
		len += 2;
		p->prec += 2;
	}
	format_hex(&s, tmp, len, p);
	free (s);
	return (p->width > len ? p->width : len);
}