/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:34:49 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/06 17:23:38 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (big[i] && (i + len_little <= len))
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
