/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:40:29 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/12 11:43:31 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;

	i = 0;
	if (!s || !f)
		return (NULL);
	a = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!a)
		return (NULL);
	while (s[i])
	{
		a[i] = f(i, s[i]);
		i++;
	}
	return (a);
}
