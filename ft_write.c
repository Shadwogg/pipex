/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:19:10 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/05 11:43:33 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_error(char *desc, char *err)
{
	if (desc != NULL)
		ft_putstr_fd(desc, 2);
	if (errno != 0)
		perror(err);
	exit(EXIT_FAILURE);
}
