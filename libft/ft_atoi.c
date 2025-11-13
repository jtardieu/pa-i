/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:50:55 by jtardieu          #+#    #+#             */
/*   Updated: 2025/09/12 00:50:55 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	nb = 0;
	i = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+' || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
