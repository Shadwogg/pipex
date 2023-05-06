/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:22:37 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 17:58:21 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	ct;

	ct = 0;
	while (ct < n)
		if (((unsigned char *) s)[ct++] == (unsigned char) c)
			return (((unsigned char *) s) + --ct);
	return ((void *)0);
}
