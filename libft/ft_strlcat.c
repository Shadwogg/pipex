/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:05:23 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/15 20:08:57 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	t;
	size_t	ct;

	t = 0;
	ct = 0;
	if (dst == NULL && dstsize == 0)
		return (0);
	while (dst[t])
		t++;
	while (src[ct] && t + ct + 1 < dstsize)
	{
		dst[t + ct] = src[ct];
		ct++;
	}
	if (dstsize != 0)
		dst[t + ct] = 0;
	return (ft_strlen(src) + ft_min(t, dstsize));
}
