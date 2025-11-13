/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:36:47 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/06 17:33:37 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exposant(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		nbchar;
	char	*envoie;
	int		sign ;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	nbchar = exposant(n) + sign;
	envoie = ft_calloc(nbchar + 1, sizeof(char));
	if (!envoie)
		return (NULL);
	envoie[nbchar] = '\0';
	while (nbchar > sign)
	{
		envoie[--nbchar] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		envoie[0] = '-';
	return (envoie);
}
