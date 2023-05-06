/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:31:59 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:37:07 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print the string and a line break.
 * Returns -1 if an error occured or the length of what is printed.
*/
int	ft_putendl_fd(char *s, int fd)
{
	int	len;
	int	len2;

	len = 0;
	if (s != NULL)
		len = write(fd, s, ft_strlen(s));
	if (len == -1)
		return (len);
	len2 = write(fd, "\n", 1);
	if (len2 == -1)
		return (-1);
	return (len + len2);
}
