/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:07:13 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/10 18:22:28 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	size;
	unsigned int	ct;

	ct = 0;
	if (s == (NULL))
		return (NULL);
	size = (unsigned int) ft_strlen((char *) s);
	str = malloc(size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (ct < size)
	{
		str[ct] = f(ct, s[ct]);
		ct++;
	}
	str[ct] = 0;
	return (str);
}
