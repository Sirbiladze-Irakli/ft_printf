/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:10:52 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 18:32:04 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// char    *form_width_hex(char *s, t_printf *p)
// {
// 	int		i;
// 	int     size;
// 	char    *s1;

// 	i = -1;
// 	if ((size = p->width - (int)ft_strlen(s)) < 0)
// 		size = 0;
// 	s1 = ft_strnew(p->width);
// 	if (ZERO == '1')
// 		s1 = ft_memset(s1, 48, p->width);
// 	else
// 		s1 = ft_memset(s1, 32, p->width);
// 	if (p->prec > (int)ft_strlen(s))
// 		s1 = form_wd_prec_hex(s, s1, p);
// 	// printf("%s - s1\n", s1);
// 	if (MINUS == '0')
// 		s1 = form_zero_hash(s, s1, p);
// 	if (MINUS == '1')
// 		s1 = form_min_hex(s, s1, p);
// 	// printf("%s - s1\n", s1);
// 	return (s1);
// }

char	*front_add_hex(char *s, t_printf *p)
{
	int		len;

	len = ft_strlen(s);
	front_add_hash(s, p, len);
	return (s);
}


void	front_add_hash(char *s, t_printf *p, int len)
{
	int		i;
	int		size;

	i  = -1;
	if (HASH == '1')
		p->prec > len ? p->prec + 2 : len + 2;
	if (p->prec > len)
		size = p->prec; 
	else
		size = len;
	if (p->specifier == 'x')
		p->hex_hash[1] = 'x';
	else
		p->hex_hash[1] = 'X';
	if (HASH == '1')
		while (p->hex_hash[++i])
			s[i] = p->hex_hash[i];
}

// char    *form_wd_prec_hex(char *s, char *s1, t_printf *p)
// {
// 	int		i;
// 	int		size;
// 	char    *h;

// 	i = 0;
// 	size = p->width - p->prec;
// 	if (MINUS == '1')
// 	{
// 		s1 = form_minus_hex(s1, s, p, (int)ft_strlen(s));
// 		return (s1);
// 	}
// 	while(i < (p->prec - (int)ft_strlen(s)))
// 		s1[size + i++] = '0';
// 	size -= 2;
// 	i = -1;
// 	if (HASH == '1')
// 	{
// 		if (p->specifier == 'x')
//     	    h = "0x";
//     	else
//     	    h = "0X";
//     	while(h[++i])
//     	    s1[size + i] = h[i];
// 	}
// 	return (s1);
// }

// char    *form_minus_hex(char *s1, char *s, t_printf *p, int len)
// {
// 	int		i;
// 	int		size;
// 	int		begin;

// 	i = 0;
// 	if (HASH == '1')
// 		size = 2;
// 	else
// 		size = 0;
// 	while(i < (p->prec - len + size))
// 		s1[i++] = '0';
// 	i = -1;
// 	if (HASH == '1')
// 		form_wd_check_hash(s1, p);
// 	begin = p->prec - len + size;
// 	while (s[++i])
// 		s1[begin + i] = s[i];
// 	return (s1);
// }

// char	*form_min_hex(char *s, char *s1, t_printf *p)
// {
// 	int		i;
// 	int		j;
// 	// char    *h;

// 	i = 0;
// 	j = 0;
// 	if (HASH == '1')
// 	{
// 		i = 2;
// 		form_wd_check_hash(s1, p);
// 	}
// 	else
// 		while (s[j])
// 			s1[i++] = s[j++];
// 	return (s1);
// }

// char    *form_prec_hex(char *s, t_printf *p)
// {
//     int     i;
//     int     size;
//     char    *s1;
    
//     i = -1;
//     if (HASH == '1')
//         s1 = ft_strnew(p->prec + 2);
//     else
//         s1 = ft_strnew(p->prec);
//     if ((size = p->prec - (int)ft_strlen(s)) < 0)
//         size = 0;
//     MINUS == '1' ? MINUS == '0' : MINUS == '0';
//     if (p->prec > (int)ft_strlen(s))
//         s1 = form_join_zero(s1, p, (int)ft_strlen(s));
//     i = -1;
//     while(s[++i])
//         s1[size + i] = s[i];
//     s1 = form_check_hash(s1, p);
//     return(s1);
// }