/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:19:10 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/04 14:50:41 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_error(char *msg)
{
	write(2, msg, get_str_len(msg));
}

int	print_error(char *str)
{
	if (str != NULL)
		perror("");
	else
		ft_printf("");
	exit(EXIT_FAILURE);
}
