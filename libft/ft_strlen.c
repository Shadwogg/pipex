/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:42:26 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 22:07:54 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns the size of the string.
*/
size_t	ft_strlen(const char *s)
{
	size_t	ct;

	ct = 0;
	while (s[ct])
		ct++;
	return (ct);
}
