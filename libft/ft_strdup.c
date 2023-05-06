/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:36:42 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/10 18:29:01 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicata;
	int		size;

	size = ft_strlen((char *) s1);
	duplicata = malloc(size * sizeof(char) + 1);
	if (duplicata == NULL)
		return ((void *) 0);
	while (size >= 0)
	{
		duplicata[size] = s1[size];
		size--;
	}
	return (duplicata);
}
