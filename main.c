/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:29:10 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/28 18:40:14 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int     main()
{
    unsigned int i = -423433503;
	// long int c = 123412343;
    // long double   a = 123.123;
    // int     a[4] = {1, 2, 3, 4};
	// char    b = '&';
	// char    c = ~b + 1;
	
    // printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "fasdf", "asfd");
	
	/********************************/
	/* 			test - hex 			*/
	/********************************/

	// ft_printf("01) %x - My\n", i);
    // printf("01) %x - Orig\n\n", i);
	
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

	ft_printf("01)|%s - My\n", "qwerty");
    printf("01)|%s - Orig\n\n", "qwerty");

    ft_printf("02)|% s - My 's'\n", "qwerty");
    printf("02)|% s - Orig 's'\n\n", "qwerty");
	
	ft_printf("03)|%15s - My 's'\n", "qwerty");
    printf("03)|%15s - Orig 's'\n\n", "qwerty");
	
	ft_printf("04)|%-15s - My 's'\n", "qwerty");
    printf("04)|%-15s - Orig 's'\n\n", "qwerty");
	
	ft_printf("05)|%15.0s - My 's'\n", "qwerty");
    printf("05)|%15.0s - Orig 's'\n\n", "qwerty");
	
	ft_printf("06)|%15.4s - My 's'\n", "qwerty");
    printf("06)|%15.4s - Orig 's'\n\n", "qwerty");
	
	ft_printf("07)|%#15.10s - My 's'\n", "qwerty");
    printf("07)|%#15.10s - Orig 's'\n\n", "qwerty");
	
	ft_printf("08)|%#-15.s - My 's'\n", "qwerty");
    printf("08)|%#-15.s - Orig 's'\n\n", "qwerty");
	
	ft_printf("09)|%#-15.4s - My 's'\n", "qwerty");
    printf("09)|%#-15.4s - Orig 's'\n\n", "qwerty");
	
	ft_printf("10)|%#-15.10s - My 's'\n", "qwerty");
    printf("10)|%#-15.10s - Orig 's'\n\n", "qwerty");
	
	ft_printf("11)|%#- 15.s - My 's'\n", "qwerty");
    printf("11)|%#- 15.s - Orig 's'\n\n", "qwerty");
	
	ft_printf("12)|%#-0 15.6s - My 's'\n", "qwerty");
    printf("12)|%#-0 15.6s - Orig 's'\n\n", "qwerty");
	
	ft_printf("13)|%-+s - My 's'\n", "qwerty");
    printf("13)|%-+s - Orig 's'\n\n", "qwerty");
	
	ft_printf("14)|%#-.13s - My 's'\n", "qwerty");
    printf("14)|%#-.13s - Orig 's'\n\n", "qwerty");
	
	ft_printf("15)|%-.4s - My 's'\n", "qwerty");
    printf("15)|%-.4s - Orig 's'\n\n", "qwerty");
	
	ft_printf("16)|%.13s - My 's'\n", "qwerty");
    printf("16)|%.13s - Orig 's'\n\n", "qwerty");
	
	ft_printf("17)|%.4s - My 's'\n", "qwerty");
    printf("17)|%.4s - Orig 's'\n\n", "qwerty");

	ft_printf("18)|%4s - My 's'\n", "qwerty");
    printf("18)|%4s - Orig 's'\n\n", "qwerty");

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