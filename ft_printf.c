/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:30:06 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/19 19:57:36 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		inhexa(unsigned long n, int i);
int		cfekoi(char c, va_list varg);

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		i;
	int		result;

	va_start (var, str);
	i = 0 ;
	result = 0 ;
	if (!str || write(1, &str[i], 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			result += cfekoi(str[i], var) + 1;
		}
		else
			result += write(1, &str[i], 1);
		i++;
	}
	va_end(var);
	return (result);
}

int	inhexa(unsigned long n, int i)
{
	static int	base;
	char		c;

	base = 0;
	if (i == 2)
	{
		if (n >= 10)
			inhexa(n / 10, i);
		c = HEXMIN[n % 10];
		write(1, &c, 1);
		return (base += 1);
	}
	else
	{
		if (n >= 16)
			inhexa(n / 16, i);
		c = HEXMIN[n % 16];
		if (i == 1)
			c = ft_toupper(c);
		write(1, &c, 1);
		return (base += 1);
	}
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
