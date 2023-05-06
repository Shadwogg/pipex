/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:16:12 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/12 11:38:08 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_get_digit(int n)
{
	int	ct;

	ct = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		ct++;
	}
	return (ct);
}

static void	ft_set(char *str, size_t size, int signe, unsigned int nb)
{
	str[size + signe] = '\0';
	while (size > 1)
	{
		str[size - 1 + signe] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	str[signe] = nb + 48;
	if (signe)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char			*str;
	int				signe;
	unsigned int	nb;
	size_t			size;

	size = ft_get_digit(n);
	nb = n;
	signe = 0;
	if (n < 0)
	{
		signe = 1;
		nb = -n;
	}
	str = malloc((signe + size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_set(str, size, signe, nb);
	return (str);
}
