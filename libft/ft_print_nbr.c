/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:31:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:46:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns the size of the number in string type (base 10)
int	ft_get_size(long x)
{
	int	ct;

	ct = 1;
	while (x > 9)
	{
		x /= 10;
		ct++;
	}
	return (ct);
}

//Returns the size of the number in string type (base 16)
int	ft_get_size_hex(unsigned int x)
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

// Print the number (base 10) to STDIN. Returns -1 if an error occured.
int	ft_print_nbr(long x)
{
	int	signe;

	signe = 0;
	if (x < 0)
	{
		x = -x;
		signe = 1;
		if (ft_putchar_fd('-', 1) == -1)
			return (-1);
	}
	if (x > 9)
	{
		if (ft_print_nbr(x / 10) == -1)
			return (-1);
		if (ft_putchar_fd(x % 10 + 48, 1) == -1)
			return (-1);
	}
	else
		if (ft_putchar_fd(x + 48, 1) == -1)
			return (-1);
	return (ft_get_size(x) + signe);
}

// Print the number (base 16) to STDIN. Returns -1 if an error occured.
int	ft_print_hexnbr(unsigned int x, int is_cap)
{
	if (x > 15)
	{
		if (ft_print_hexnbr(x / 16, is_cap) == -1)
			return (-1);
		if (ft_put_hexnbr(x % 16 + 48, is_cap) == -1)
			return (-1);
	}
	else
		if (ft_put_hexnbr(x + 48, is_cap) == -1)
			return (-1);
	return (ft_get_size_hex(x));
}
