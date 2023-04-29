/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:19:10 by ggiboury          #+#    #+#             */
/*   Updated: 2023/02/24 00:14:11 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_error(char *msg)
{
	write(2, msg, get_str_len(msg));
}

/// @brief Print an error to the stderr then exit the program.
int	print_error(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
