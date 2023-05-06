/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:34:20 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:58:50 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rec_putnbr_fd(unsigned int nb, int fd)
{
	if (nb > 9)
	{
		if (ft_rec_putnbr_fd(nb / 10, fd) == -1)
			return (-1);
		if (ft_putchar_fd(nb % 10 + 48, fd) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd(nb + 48, fd) == -1)
			return (-1);
	}
	return (1);
}

int	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nb2;

	if (nb < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		nb2 = -nb;
	}
	else
		nb2 = nb;
	return (ft_rec_putnbr_fd(nb2, fd));
}
