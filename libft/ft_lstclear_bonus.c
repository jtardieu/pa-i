/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtardieu <jtardieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:58:20 by jtardieu          #+#    #+#             */
/*   Updated: 2025/11/11 16:02:19 by jtardieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*dellist;
	t_list	*nextlist;

	if (!lst)
		return ;
	dellist = *lst;
	while (dellist)
	{
		nextlist = dellist->next;
		ft_lstdelone(dellist, del);
		dellist = nextlist;
	}
	*lst = NULL;
}
