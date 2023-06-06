/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:13:00 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/06 17:26:04 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_cmd(t_cmd *cmd, char **env)
{
	errno = 0;
	if (set_cmd(cmd, env) == -1)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	if (dup2(cmd->in, 0) == -1)
		print_error("", "dup2(in) failed");
	if (dup2(cmd->out, 1) == -1)
		print_error("", "dup2(out) failed");
	execve(cmd->option[0], cmd->option, env);
	free_cmds(&cmd, 1);
	perror(ft_strjoin(cmd->option[0], cmd->option[1]));
	return (-1);
}
