/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:30:06 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/18 18:09:52 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	inhexa(unsigned int n, int i);
void	cfekoi(char c, va_list varg);

int	ft_printf(const char *str, ...)
{
	va_list	var;
	int		i;
	int		j;

	va_start (var, str);
	i = 0 ;
	j = 0 ;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cfekoi(str[i], var);
			j++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(var);
	return (i-j);
}

void	inhexa(unsigned int n, int i)
{
	char	*base16;
	char	*base10;
	char	c;

	base10 = "0123456789";
	base16 = "0123456789abcdef";
	if (i == 2)
	{
		if (n >= 10)
			inhexa(n / 10, i);
		c = base10[n % 10];
		write(1, &c, 1);
		return ;
	}
	else
	{
		if (n >= 16)
			inhexa(n / 16, i);
		c = base16[n % 16];
		if (i == 1)
			c = ft_toupper(c);
		write(1, &c, 1);
		return ;
	}
}

void	cfekoi(char c, va_list var)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(var, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(var, char *), 1);
	else if (c == 'x')
		inhexa(va_arg(var, unsigned int), 0);
	else if (c == 'X')
		inhexa(va_arg(var, unsigned int), 1);
	else if (c == 'u')
		inhexa(va_arg(var, unsigned int), 2);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		inhexa(va_arg(var, size_t), 0);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(var, int), 1);
	else
		write(1, &c, 1);
}
