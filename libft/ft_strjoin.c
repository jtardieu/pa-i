/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:43:25 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/06 17:28:36 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	tab = ft_calloc(i, sizeof(char));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1, i);
	ft_strlcat(tab, s2, i);
	return (tab);
}
