/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:38:19 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:09:31 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in(char c, char *set)
{
	while (set)
	{
		if (c == *set)
			return (1);
		set += 1;
	}
	return (0);
}

int	ft_isvalid_str(const char *str)
{
	int	ct;

	ct = 0;
	while (str[ct])
	{
		if (str[ct] == '%')
			if ((str[++ct] == 0) || !ft_is_in(str[ct], "cspdiuxX%"))
				return (0);
		ct++;
	}
	return (1);
}

int	ft_end(va_list *ptr)
{
	va_end(*ptr);
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		ct;
	int		size;
	int		err;

	ct = -1;
	size = 0;
	va_start(ptr, str);
	if (!ft_isvalid_str(str))
		return (ft_end(&ptr));
	while (str[++ct])
	{
		if (str[ct] == '%' && ft_is_in(str[ct + 1], "cspdiuxX%"))
			err = ft_print_arg(str[++ct], ptr);
		else
			err = write(1, (char *) str + ct, 1);
		if (err == -1)
			return (ft_end(&ptr));
		size += err;
	}
	va_end(ptr);
	return (size);
}
