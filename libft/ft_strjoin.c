/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:59:19 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 14:50:37 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		ct;
	int		ct2;

	if (s1 == NULL)
		return (ft_strdup(s2));
	ct = 0;
	ct += ft_strlen(s1) + ft_strlen(s2);
	string = malloc((ct) * sizeof(char) + 1);
	if (string == NULL)
		return (NULL);
	ct = 0;
	ct2 = 0;
	while (s1[ct])
	{
		string[ct] = s1[ct];
		ct++;
	}
	while (s2[ct2])
	{
		string[ct + ct2] = s2[ct2];
		ct2++;
	}
	string[ct + ct2] = 0;
	return (string);
}
