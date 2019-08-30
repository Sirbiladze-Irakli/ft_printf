/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:29:10 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/30 17:37:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int     main()
{
    unsigned int i = 14532;
	// long int c = 123412343;
    // long double   a = 123.123;
    // int     a[4] = {1, 2, 3, 4};
	// char    b = '&';
	// char    c = ~b + 1;
	
    // printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "fasdf", "asfd");
	
	/********************************/
	/* 			test - hex 			*/
	/********************************/

	// ft_printf("01) %#6.5x| - My\n", i);
    // printf("01) %#6.5x| - Orig\n\n", i);
	
    // ft_printf("02) %#x - My\n", i);
    // printf("02) %#x - Orig\n\n", i);
	
	// ft_printf("03) %#15x - My\n", i);
    // printf("03) %#15x - Orig\n\n", i);
	
	// ft_printf("04) %#-15x - My\n", i);
    // printf("04) %#-15x - Orig\n\n", i);
	
	// ft_printf("05) %15x - My\n", i);
    // printf("05) %15x - Orig\n\n", i);
	
	// ft_printf("06) %-15x - My\n", i);
    // printf("06) %-15x - Orig\n\n", i);
	
	// ft_printf("07) %#15.x - My\n", i);
    // printf("07) %#15.x - Orig\n\n", i);
	
	// ft_printf("08) %#15.6x - My\n", i);
    // printf("08) %#15.6x - Orig\n\n", i);
	
	// ft_printf("09) %#15.10x - My\n", i);
    // printf("09) %#15.10x - Orig\n\n", i);
	
	// ft_printf("10) %#15.13x - My\n", i);
    // printf("10) %#15.13x - Orig\n\n", i);
	
	// ft_printf("11) %#-15.x - My\n", i);
    // printf("11) %#-15.x - Orig\n\n", i);
	
	// ft_printf("12) %#-15.6x - My\n", i);
    // printf("12) %#-15.6x - Orig\n\n", i);
	
	// ft_printf("13) %#-15.10x - My\n", i);
    // printf("13) %#-15.10x - Orig\n\n", i);
	
	// ft_printf("14) %#-15.13x - My\n", i);
    // printf("14) %#-15.13x - Orig\n\n", i);
	
	// ft_printf("15) %-015x - My\n", i);
    // printf("15) %-015x - Orig\n\n", i);
	
	// ft_printf("16) %15.13x - My\n", i);
    // printf("16) %15.13x - Orig\n\n", i);
	
	// ft_printf("17) %-15.13x - My\n", i);
    // printf("17) %-15.13x - Orig\n\n", i);
	

	/********************************/
	/* 			test - str 			*/
	/********************************/

	// ft_printf("01)|%s| - My 's'\n", "qwerty");
    // printf("01)|%s| - Orig 's'\n\n", "qwerty");

    // ft_printf("02)|% s| - My 's'\n", "qwerty");
    // printf("02)|% s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("03)|%10s| - My 's'\n", "qwerty");
    // printf("03)|%10s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("04)|%-10s| - My 's'\n", "qwerty");
    // printf("04)|%-10s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("05)|%15.0s| - My 's'\n", "qwerty");
    // printf("05)|%15.0s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("06)|%13.4s| - My 's'\n", "qwerty");
    // printf("06)|%13.4s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("07)|%#15.10s| - My 's'\n", "qwerty");
    // printf("07)|%#15.10s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("08)|%#-15.s| - My 's'\n", "qwerty");
    // printf("08)|%#-15.s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("09)|%#-15.4s| - My 's'\n", "qwerty");
    // printf("09)|%#-15.4s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("10)|%#-15.10s| - My 's'\n", "qwerty");
    // printf("10)|%#-15.10s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("11)|%#- 15.s| - My 's'\n", "qwerty");
    // printf("11)|%#- 15.s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("12)|%#-0 15.6s| - My 's'\n", "qwerty");
    // printf("12)|%#-0 15.6s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("13)|%-+s| - My 's'\n", "qwerty");
    // printf("13)|%-+s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("14)|%#-.13s| - My 's'\n", "qwerty");
    // printf("14)|%#-.13s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("15)|%-.4s| - My 's'\n", "qwerty");
    // printf("15)|%-.4s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("16)|%.13s| - My 's'\n", "qwerty");
    // printf("16)|%.13s| - Orig 's'\n\n", "qwerty");
	
	// ft_printf("17)|%.4s| - My 's'\n", "qwerty");
    // printf("17)|%.4s| - Orig 's'\n\n", "qwerty");

	// ft_printf("18)|%4s| - My 's'\n", "qwerty");
    // printf("18)|%4s| - Orig 's'\n\n", "qwerty");

	/********************************/
	/* 			test - char			*/
	/********************************/

	// ft_printf("01)|%c| - My 'c'\n", 'a');
    // printf("01)|%c| - Orig 'c'\n\n", 'a');

    // ft_printf("02)|% c| - My 'c'\n", 'a');
    // printf("02)|% c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("03)|%15c| - My 'c'\n", 'a');
    // printf("03)|%15c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("04)|%-10c| - My 'c'\n", 'a');
    // printf("04)|%-10c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("05)|%15.0c| - My 'c'\n", 'a');
    // printf("05)|%15.0c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("06)|%13.4c| - My 'c'\n", 'a');
    // printf("06)|%13.4c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("07)|%#15.10c| - My 'c'\n", 'a');
    // printf("07)|%#15.10c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("08)|%#-15.c| - My 'c'\n", 'a');
    // printf("08)|%#-15.c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("09)|%#-15.4c| - My 'c'\n", 'a');
    // printf("09)|%#-15.4c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("10)|%#-15.10c| - My 'c'\n", 'a');
    // printf("10)|%#-15.10c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("11)|%#- 15.c| - My 'c'\n", 'a');
    // printf("11)|%#- 15.c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("12)|%#-0 15.6c| - My 'c'\n", 'a');
    // printf("12)|%#-0 15.6c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("13)|%-+c| - My 'c'\n", 'a');
    // printf("13)|%-+c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("14)|%#-.13c| - My 'c'\n", 'a');
    // printf("14)|%#-.13c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("15)|%-.4c| - My 'c'\n", 'a');
    // printf("15)|%-.4c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("16)|%.13c| - My 'c'\n", 'a');
    // printf("16)|%.13c| - Orig 'c'\n\n", 'a');
	
	// ft_printf("17)|%.4c| - My 'c'\n", 'a');
    // printf("17)|%.4c| - Orig 'c'\n\n", 'a');

	// ft_printf("18)|%4c| - My 'c'\n", 'a');
    // printf("18)|%4c| - Orig 'c'\n\n", 'a');

	/********************************/
	/* 			test - int			*/
	/********************************/

	// ft_printf("01)|%d| - My 'di'\n", 2147483647);
    // printf("01)|%d| - Orig 'di'\n\n", 2147483647);

    // ft_printf("02)|% d| - My 'di'\n", 2147483647);
    // printf("02d|% d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("03)|%10d| - My 'di'\n", 2147483647);
    // printf("03)d%10d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("04)|%-10d| - My 'di'\n", 2147483647);
    // printf("04)|d-10d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("05)|%15.0d| - My 'di'\n", 2147483647);
    // printf("05)|%d5.0d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("06)|%13.4d| - My 'di'\n", 2147483647);
    // printf("06)|%d3.4d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("07)|%#15.10d| - My 'di'\n", 2147483647);
    // printf("07)|%#1d.10d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("08)|%#-15.d| - My 'di'\n", 2147483647);
    // printf("08)|%#d15.d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("09)|%#-15.4d| - My 'di'\n", 2147483647);
    // printf("09)|%#-d5.4d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("10)|%#-15.10d| - My 'di'\n", 2147483647);
    // printf("10)|%#-1d.10d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("11)|%#- 15.d| - My 'di'\n", 2147483647);
    // printf("11)|%#-d15.d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("12)|%#-0 15.6d| - My 'di'\n", 2147483647);
    // printf("12)|%#-0 d5.6d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("13)|%-+d| - My 'di'\n", 2147483647);
    // printf("13)d%-+d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("14)|%#-.13d| - My 'di'\n", 2147483647);
    // printf("14)|%#d.13d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("15)|%-.4d| - My 'di'\n", 2147483647);
    // printf("15)|d-.4d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("16)|%.13d| - My 'di'\n", 2147483647);
    // printf("16)|d.13d| - Orig 'di'\n\n", 2147483647);
	
	// ft_printf("17)|%.4d| - My 'di'\n", 2147483647);
    // printf("17)d%.4d| - Orig 'di'\n\n", 2147483647);

	// ft_printf("18)|%4d| - My 'di'\n", 2147483647);
    // printf("18d|%4d| - Orig 'di'\n\n", 2147483647);

	/********************************/
	/* 			test - ptr			*/
	/********************************/

	ft_printf("01)|%p| - My 'p'\n", &i);
    printf("01)|%p| - Orig 'p'\n\n", &i);

    ft_printf("02)|% p| - My 'p'\n", &i);
    printf("02)|% p| - Orig 'p'\n\n", &i);
	
	ft_printf("03)|%20p| - My 'p'\n", &i);
    printf("03)|%20p| - Orig 'p'\n\n", &i);
	
	ft_printf("04)|%-20p| - My 'p'\n", &i);
    printf("04)|%-20p| - Orig 'p'\n\n", &i);
	
	ft_printf("05)|%20.0p| - My 'p'\n", &i);
    printf("05)|%20.0p| - Orig 'p'\n\n", &i);
	
	ft_printf("06)|%27.4p| - My 'p'\n", &i);
    printf("06)|%27.4p| - Orig 'p'\n\n", &i);
	
	ft_printf("07)|%#24.10p| - My 'p'\n", &i);
    printf("07)|%#24.10p| - Orig 'p'\n\n", &i);
	
	ft_printf("08)|%#-25.p| - My 'p'\n", &i);
    printf("08)|%#-25.p| - Orig 'p'\n\n", &i);
	
	ft_printf("09)|%#24.14p| - My 'p'\n", &i);
    printf("09)|%#24.14p| - Orig 'p'\n\n", &i);
	
	ft_printf("10)|%#-26.10p| - My 'p'\n", &i);
    printf("10)|%#-26.10p| - Orig 'p'\n\n", &i);
	
	ft_printf("11)|%#- 26.p| - My 'p'\n", &i);
    printf("11)|%#- 26.p| - Orig 'p'\n\n", &i);
	
	ft_printf("12)|%#-0 28.16p| - My 'p'\n", &i);
    printf("12)|%#-0 28.16p| - Orig 'p'\n\n", &i);
	
	ft_printf("13)|%-+p| - My 'p'\n", &i);
    printf("13)|%-+p| - Orig 'p'\n\n", &i);
	
	ft_printf("14)|%#-.26p| - My 'p'\n", &i);
    printf("14)|%#-.26p| - Orig 'p'\n\n", &i);
	
	ft_printf("15)|%-.4p| - My 'p'\n", &i);
    printf("15)|%-.4p| - Orig 'p'\n\n", &i);
	
	ft_printf("16)|%.16p| - My 'p'\n", &i);
    printf("16)|%.16p| - Orig 'p'\n\n", &i);
	
	ft_printf("17)|%.4p| - My 'p'\n", &i);
    printf("17)|%.4p| - Orig 'p'\n\n", &i);

	ft_printf("18)|%030p| - My 'p'\n", &i);
    printf("18)|%030p| - Orig 'p'\n\n", &i);

	ft_printf("19)|%0.30p| - My 'p'\n", &i);
    printf("19)|%0.30p| - Orig 'p'\n\n", &i);

	ft_printf("20)|%13.12p| - My 'p'\n", &i);
    printf("20)|%13.12p| - Orig 'p'\n\n", &i);

	ft_printf("21)|%14.13p| - My 'p'\n", &i);
    printf("21)|%14.13p| - Orig 'p'\n\n", &i);

	ft_printf("22)|%14.14p| - My 'p'\n", &i);
    printf("22)|%14.14p| - Orig 'p'\n\n", &i);

	// ft_printf("%s - My\n", "asdf");
	// printf("%s - Orig\n", "asdf");
    // printf("%-15u\n", i);
    // printf("Raspberry Pi %d%%\n", 3);
	// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", "str");
    // printf("%c\n", 'g');

    // printf("%-6.4s\n", "Irakli");
	// printf("%3c\n", 'c');
	// printf("%d\n", 34);
	// printf("%i\n", 2047);
	// printf("%Lo\n", c);
	// printf("%20Lx\n", 1024);
	// printf("%Lp\n", &c);
	// printf("%+%");
	// printf("%Lf\n", a);
	
    // printf("%p\n", "wefwv");
	// printf("%5. 6. 4d\n", 2);
    return (0);
}