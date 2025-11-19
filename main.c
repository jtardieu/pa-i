/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:23:28 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/19 15:55:58 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	char a = av[1][0];
	char *b = av[2];
	int c = ft_atoi(av[3]);

	int e;

	ft_printf("ft\n");
	ft_printf("%c \n", '0');
	e = ft_printf(" %c \n", '0');
	ft_printf(" %d \n", e);
	ft_printf(" %c \n", '0' - 256);
	ft_printf("%c \n", '0' + 256);
	ft_printf(" %c %c %c \n", '1', '2', '3');
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n\n", 0, '1', '2');

	printf("print\n");
	printf("%c \n", '0');
	e = printf(" %c \n", '0');
	printf(" %d \n", e);
	printf(" %c \n", '0' - 256);
	printf("%c \n", '0' + 256);
	printf(" %c %c %c \n", '1', '2', '3');
	printf(" %c %c %c \n", '2', '1', 0);
	printf(" %c %c %c \n\n", 0, '1', '2');

	ft_printf("ft\n");
	ft_printf(" %d \n", 0);
	ft_printf(" %d \n", -1);
	ft_printf(" %d \n", 10);
	ft_printf(" %d \n", 11);
	ft_printf(" %d \n", 100);
	ft_printf(" %d \n", -100);
	e=ft_printf(" %d .\n", INT_MIN);
		ft_printf("char %d\n",e);

	printf("\n\nprint\n");
	printf(" %d \n", 0);
	printf(" %d \n", -1);
	printf(" %d \n", 1);
	printf(" %d \n", 10);
	printf(" %d \n", 11);
	printf(" %d \n", 100);
	printf(" %d \n", -100);
	e=printf(" %d .\n", INT_MIN);
	ft_printf("char %d\n\n",e);

	e = ft_printf("%c\t", a);
	ft_printf("char %d\n",e);
    e = ft_printf("%s\t", b);
	ft_printf("char %d\n",e);
    e = ft_printf("%p\t", NULL);
    ft_printf("char %d\n",e);
	e = ft_printf("%d\t", c);
	ft_printf("char %d\n",e);
    e = ft_printf("%i\t", 1337);
	ft_printf("char %d\n",e);
    e = ft_printf("%u\t", 3000000000U);
	ft_printf("char %d\n",e);
    e = ft_printf("%x\t", 0);
	ft_printf("char %d\n",e);
    e = ft_printf("%X\t", 48879);
	ft_printf("char %d\n",e);
    e = ft_printf("%%\t");
	ft_printf("char %d\n",e);
	e = ft_printf("ft une bite de moine %c\n hun hun %s\n chifre %d\n",a,b,c);
	ft_printf("char %d\n\n",e);

	printf("Char: %c\n", a);
    printf("String: %s\n", b);
    printf("Pointer: %p\n", NULL);
    printf("Decimal: %d\n", INT_MIN);
    printf("Integer: %i\n", 1337);
    printf("Unsigned: %u\n", 3000000000U);
    e=printf("%x\n", 0);
	ft_printf("char %d\n\n",e);
	printf("Hex upper: %X\n", 48879);
    printf("Percent: %%\n");
	printf("chien d'home %c\n la suite %s\nchifre %d\n",a,b,c);
	return 0;
}


int	cfekoi(char c, va_list var)
{
	size_t	i;

	if (c == 'c')
		ft_putchar_fd(va_arg(var, int), 1);
	else if (c == 's')
		return (ft_putstr_fd(va_arg(var, char *), 1) - 1);
	else if (c == 'x')
		return (inhexa(va_arg(var, unsigned int), 0) - 1);
	else if (c == 'X')
		return (inhexa(va_arg(var, unsigned int), 1) - 1);
	else if (c == 'u')
		return (inhexa(va_arg(var, unsigned int), 2) - 1);
	else if (c == 'p')
	{
		i = va_arg(var, size_t);
		if (!i)
			return (write(1, "(nil)", 5) - 1);
		else
			return ((write(1, "0x", 2) - 1) + inhexa(i, 0));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(var, int), 1));
	else
		write(1, &c, 1);
	return (0);
}