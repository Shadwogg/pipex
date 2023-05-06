/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:47:36 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/14 21:02:10 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ct;

	if (lst == NULL)
		return (0);
	ct = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		ct++;
	}
	return (ct);
}
