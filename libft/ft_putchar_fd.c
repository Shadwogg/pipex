/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:26:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 21:30:00 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Print the character.
 * Returns -1 if an error occured or the length of what is printed.
*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
