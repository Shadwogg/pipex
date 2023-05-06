/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:53:10 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 22:08:54 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Set the space occupied by s to 0.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	ct;

	string = (char *) s;
	ct = 0;
	while (ct < n)
		string[ct++] = 0;
}
