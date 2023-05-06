/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:57:39 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 14:27:00 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_there(const char *needle, const char *haystack)
{
	int	ct;

	ct = 0;
	while (needle[ct] && haystack[ct])
	{
		if (needle[ct] != haystack[ct])
			return (0);
		ct++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ct;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[0] == 0)
		return ((char *) haystack);
	ct = 0;
	while (haystack[ct] && ct + ft_strlen((char *) needle) - 1 < len)
	{
		if (ft_is_there(needle, (haystack + ct)))
			return ((char *)(haystack + ct));
		ct++;
	}
	return (NULL);
}
