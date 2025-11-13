/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:45:15 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/12 13:20:24 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sorc;

	dst = (unsigned char *)dest;
	sorc = (unsigned char *)src;
	if (sorc < dst)
	{
		while (n != 0)
		{
			n--;
			dst[n] = sorc[n];
		}
	}
	else
		ft_memcpy(dst, sorc, n);
	return (dest);
}
