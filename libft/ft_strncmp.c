/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:03:45 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/10 18:09:06 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ct;

	ct = 0;
	while (s1[ct] && s2[ct] && ct < n)
	{
		if (s1[ct] != s2[ct])
			return ((unsigned char) s1[ct] - (unsigned char) s2[ct]);
		ct++;
	}
	if (ct < n)
	{
		if (s1[ct])
			return (1);
		else if (s2[ct])
			return (-1);
	}
	return (0);
}
