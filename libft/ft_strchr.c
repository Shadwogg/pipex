/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:56:39 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/16 18:07:15 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	ct;

	ct = -1;
	while (s[++ct])
		if (s[ct] == (char) c)
			return ((char *)(s + ct));
	if (s[ct] == (char) c)
		return ((char *)(s + ct));
	return (0);
}
