/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:28:35 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 14:47:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_lst;
	t_list	*nex_lst;

	if (lst == NULL || *lst == NULL)
		return ;
	cur_lst = *lst;
	while (cur_lst->next != NULL)
	{
		nex_lst = cur_lst->next;
		ft_lstdelone(cur_lst, del);
		cur_lst = nex_lst;
	}
	ft_lstdelone(cur_lst, del);
	*lst = NULL;
}
