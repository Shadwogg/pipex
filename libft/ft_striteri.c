/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:11:24 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 18:14:48 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	ct;
	unsigned int	size;

	if (s == NULL)
		return ;
	ct = 0;
	size = (unsigned int) ft_strlen(s);
	while (ct < size)
	{
		f(ct, s + ct);
		ct++;
	}
}
