/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:27:32 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/14 16:47:31 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ct;

	ct = 0;
	while (ct + 1 < dstsize && src[ct])
	{
		dst[ct] = src[ct];
		ct++;
	}
	if (dstsize > 0)
		dst[ct] = 0;
	return (ft_strlen((char *) src));
}
