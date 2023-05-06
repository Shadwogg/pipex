/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:24:04 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 17:59:54 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			ct;

	if (n == 0)
		return (0);
	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	ct = 0;
	while (ct < n)
	{
		if (string1[ct] != string2[ct])
			return (string1[ct] - string2[ct]);
		ct++;
	}
	return (0);
}
