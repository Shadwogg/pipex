/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:50:28 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 22:08:30 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Fill the memory with the number given
*/
void	*ft_memset(void *s, int nb, size_t size)
{
	int		ct;
	char	*string;

	string = s;
	ct = -1;
	while (((size_t)(++ct)) < size)
		string[ct] = (unsigned char) nb;
	return (s);
}
