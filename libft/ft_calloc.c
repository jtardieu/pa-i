/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:46:20 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/12 12:08:17 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t nmemb, size_t size )
{
	size_t	i ;
	void	*tab;

	i = nmemb * size ;
	if (size && (i / size != nmemb))
		return (NULL);
	tab = malloc(i);
	if (!tab)
		return (NULL);
	else
		ft_bzero (tab, i);
	return (tab);
}
