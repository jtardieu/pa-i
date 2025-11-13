/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:23:28 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/13 15:39:29 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

void affiche(int i,...);

int main(int ac , char **av)
{
	(void) ac;
	affiche(atoi(av[3]),av[1],av[2]);
	return 0;

}

void affiche(int i, ...)
{

	char argu ;
	va_list infoparam;
	
	va_start (infoparam,i);
	argu = (char)va_arg(infoparam,int);
	printf("j imagine space c ca %c",argu);
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

