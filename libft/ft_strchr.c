/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:46:29 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/12 13:18:21 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cast_c;
	int		i;

	cast_c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cast_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cast_c)
		return ((char *)&s[i]);
	return (0);
}
