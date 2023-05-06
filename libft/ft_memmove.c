/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:39:16 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/14 16:42:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		ct;

	if (n == 0 || (src == NULL && dst == NULL))
		return (dst);
	if (dst < src)
	{
		ct = 0;
		while (ct < n)
		{
			((char *) dst)[ct] = ((const char *) src)[ct];
			ct++;
		}
	}
	else
	{
		ct = n - 1;
		while (ct > 0)
		{
			((char *) dst)[ct] = ((const char *) src)[ct];
			ct--;
		}
		((char *) dst)[ct] = ((const char *) src)[ct];
	}
	return (dst);
}
