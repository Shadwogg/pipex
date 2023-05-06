/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:54:17 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/15 18:26:51 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	ct;
	size_t			ct2;
	size_t			true_len;
	char			*str;	

	if (s == NULL)
		return (NULL);
	ct = 0;
	true_len = 0;
	while (s[ct] && ct < start)
		ct++;
	while (s[ct + true_len] && true_len < len)
		true_len++;
	str = malloc((true_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ct2 = 0;
	while (s[ct] && ct2 < true_len)
		str[ct2++] = s[ct++];
	str[ct2] = 0;
	return (str);
}
