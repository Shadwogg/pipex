/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:37:21 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 18:56:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*ft_free(void *tmp, t_list **new_lst, void (*del)(void *))
{
	free(tmp);
	ft_lstclear(new_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cur_lst;
	void	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst->content);
	new_lst = ft_lstnew(tmp);
	if (new_lst == NULL)
		return (ft_free(tmp, &new_lst, del));
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		cur_lst = ft_lstnew(tmp);
		if (cur_lst == NULL)
			return (ft_free(tmp, &new_lst, del));
		ft_lstadd_back(&new_lst, cur_lst);
		lst = lst->next;
	}
	return (new_lst);
}
