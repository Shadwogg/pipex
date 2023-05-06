/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:00:38 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:47:38 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size_hexptr(unsigned long x)
{
	int	ct;

	ct = 1;
	while (x > 15)
	{
		x /= 16;
		ct++;
	}
	return (ct);
}

int	ft_print_hexptr(unsigned long x)
{
	if (x > 15)
	{
		ft_print_hexptr(x / 16);
		if (ft_put_hexnbr(x % 16 + 48, 0) == -1)
			return (-1);
	}
	else
	{
		if (ft_put_hexnbr(x + 48, 0) == -1)
			return (-1);
	}
	return (ft_get_size_hexptr(x));
}

int	ft_print_pointer(void *x)
{
	int	err;

	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	err = ft_print_hexptr((unsigned long) x);
	if (err == -1)
		return (-1);
	return (err + 2);
}
