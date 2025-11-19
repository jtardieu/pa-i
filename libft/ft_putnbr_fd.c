/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:45:12 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/19 16:09:59 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	static int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (10);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
		i++;
	}
	else if (n > 9)
	{
		i = ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
		i++;
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
	return (i);
}
