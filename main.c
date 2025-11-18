/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:23:28 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/18 01:07:08 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "printf.h"

#include <stdio.h>

void	affiche(int i, ...);

int	main(int ac, char **av)
{
	(void) ac;
	//affiche(atoi(av[3]), *av[1], *av[2]);
	char a = av[1][0];
	char *b = av[2];
	int c = ft_atoi(av[3]);


	ft_printf("ft Char: %c\n", a);
    ft_printf("ft String: %s\n", b);
    ft_printf("ft Pointer: %p\n", (void *)0x1234abcd);
    ft_printf("ft Decimal: %d\n", c);
    ft_printf("ft Integer: %i\n", 1337);
    ft_printf("ft Unsigned: %u\n", 3000000000U);
    ft_printf("ft Hex lower: %x\n", -900000000);
    ft_printf("ft Hex upper: %X\n", 48879);
    ft_printf("ft Percent: %%\n");
	ft_printf("ft une bite de moine %c\n hun hun %s\n chifre %d\n\n",a,b,c);

	printf("Char: %c\n", a);
    printf("String: %s\n", b);
    printf("Pointer: %p\n", (void *)0x1234abcd);
    printf("Decimal: %d\n", c);
    printf("Integer: %i\n", 1337);
    printf("Unsigned: %u\n", 3000000000U);
    printf("Hex lower: %x\n", -900000000);
    printf("Hex upper: %X\n", 48879);
    printf("Percent: %%\n");
	printf("chien d'home %c\n la suite %s\nchifre %d\n",a,b,c);
	return 0;
}

void	affiche(int i, ...)
{
	int		j = 0;
	char	argu ;
	va_list	infoparam;
	va_start (infoparam, i);
	while (j != i)
	{
		argu = (char )va_arg(infoparam, int);
		printf("j imagine space c ca %c\n",argu);
		j++;
	}
	va_end(infoparam);
}

// #include <stdarg.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// int maximum( int first, ... ) {

//     int max = first;
//     va_list parametersInfos;
//     /* Initialize the va_list structure */
//     va_start( parametersInfos, first );

//     while( true ) {

//         /* Extraction of the next integer */
//         int current = (int) va_arg( parametersInfos, int );

//         if ( current == -1 ) break;

//         if ( current > max ) {
//             max = current;
//         }

//     }

//     /* Release va_list resources */
//     va_end( parametersInfos );

//     return max;
// }

// int main( int argc, char * argv[] ) {

//     int result = maximum( 2, 11, 5, -1 );
//     printf( "maximum( 2, 11, 5, -1 ) == %d\n", result );     /* 11 */


//     result = maximum( 3, 8, 12, 1, -1 );
//     printf( "maximum( 3, 8, 12, 1, -1 ) == %d\n", result );  /* 12 */

//     return EXIT_SUCCESS;

// }

