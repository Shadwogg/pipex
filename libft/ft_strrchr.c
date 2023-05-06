/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:07:39 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/14 17:43:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*occur;
	int		ct;

	ct = -1;
	occur = (void *) 0;
	while (s[++ct])
		if (s[ct] == (char) c)
			occur = (char *)(s + ct);
	if (s[ct] == (char) c)
		return ((char *)(s + ct));
	return (occur);
}
