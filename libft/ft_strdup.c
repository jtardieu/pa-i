/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:18:17 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/12 13:18:42 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*transfert;
	size_t	taille;
	int		i;

	i = 0;
	taille = ft_strlen(s);
	transfert = malloc(sizeof(char) * taille + 1);
	if (transfert == NULL)
		return (0);
	while (s[i])
	{
		transfert[i] = s[i];
		i++;
	}
	transfert[i] = '\0';
	return (transfert);
}
