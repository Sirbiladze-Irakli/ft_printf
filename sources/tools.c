/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:16:42 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/28 20:16:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_nbrlen(unsigned long i)
{
    unsigned long   tmp;
    int             counter;

    tmp = i;
    counter = 0;
    while (tmp > 0)
    {
        tmp /= 10;
        counter++;   
    }
    return (counter);
}

void    ft_strdup_free(char **s, char *arg, t_printf *p)
{
    char    *tmp;

    tmp = ft_strdup(arg);
    *s = tmp;
    free(tmp);
}

void	ft_strsub_free(char **s, char *tmp, t_printf *p)
{
	int		i;
	char	*subs;

	if (s == NULL)
		return ;
	if (!(subs = (char *)malloc(sizeof(char) * (p->width))))
		return ;
	i = -1;
	printf("%s - subs\n", subs);
    while (++i < p->prec)
    {
		subs[i] = *s[i];
        printf("%c - subo\n", subs[i]);
    }
    printf("%s - subs\n", subs);
    while(subs[i])
        subs[i++] = ' ';
    printf("%s - sub\n", subs);
	*s = subs;
	free(subs);
}