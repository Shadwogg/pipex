/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:11:42 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/11 20:04:14 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	ct;

	ct = 0;
	while (set[ct])
		if (c == set[ct++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		start;
	int		end;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && ft_in_set(s1[end], set))
		end--;
	if (start > end)
	{
		string = ft_calloc(1, sizeof(char));
		return (string);
	}
	string = ft_substr(s1, start, end - start + 1);
	return (string);
}
