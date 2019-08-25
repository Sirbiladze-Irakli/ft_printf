#include "../includes/ft_printf.h"

void    parse_struct(char *buf, t_printf *p)
{
	int	i;

	i = 0;
    struct_init(p);
    while (buf[++i])
    {
		if (buf[i] == '-')
			MINUS = '1';
		if (buf[i] == '0' && !ft_compare_chr(".0123456789", buf[i - 1]))
			ZERO = '1';
		if (buf[i] == '+')
			PLUS = '1';
		if (buf[i] == '#')
			HASH = '1';
		if (buf[i] == ' ')
			SPACE = '1';
		if (ft_compare_chr("123456789", buf[i]) && buf[i - 1] != '.')
        	i = width_converter(p, buf, i);
		if (buf[i - 1] == '.')
        	i = prec_converter(p, buf, i);
		if (ft_compare_chr("hlL", buf[i]))
			i = modif_checker(p, buf, i);
	}
}