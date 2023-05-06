/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:59 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:52:39 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_str(char *str)
{
	int	ct;

	ct = 0;
	if (str == NULL)
		return (ft_put_str("(null)"));
	if (*str == 0)
		return (0);
	return (ft_putstr_fd(str, 1));
}

int	ft_put_hexnbr(unsigned int x, int is_cap)
{
	if (x > '9')
		x += 39;
	if (is_cap == 1)
	{
		if (ft_putchar_fd(ft_toupper(x), 1) == -1)
			return (-1);
	}
	else if (is_cap != 1)
		if (ft_putchar_fd((char) x, 1) == -1)
			return (-1);
	return (1);
}

int	ft_print_arg(char c, va_list lst)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(lst, int), 1));
	else if (c == 's')
		return (ft_put_str(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(lst, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(lst, int)));
	else if (c == 'u')
		return (ft_print_nbr(va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (ft_print_hexnbr(va_arg(lst, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hexnbr(va_arg(lst, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}
