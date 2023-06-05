/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:13:00 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/05 11:47:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd(t_cmd *cmd, char **env)
{
	if (set_cmd(cmd, env) == -1)
		print_error("command not found\n", "");
	if (dup2(cmd->in, 0) == -1)
		print_error("", "dup2(in) failed");
	if (dup2(cmd->out, 1) == -1)
		print_error("", "dup2(out) failed");
	execve(cmd->option[0], cmd->option, env);
	perror(cmd->option[0]);
	return (-1);
}
