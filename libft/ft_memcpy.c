/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:46:55 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/10 18:11:30 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		ct;
	char		*copie;
	const char	*source;

	if (src == NULL && dst == NULL)
		return (NULL);
	copie = dst;
	source = src;
	ct = 0;
	while (ct < n)
	{
		copie[ct] = source[ct];
		ct++;
	}
	return (dst);
}
