/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:06:26 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/07 22:43:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_all(int **pipes)
{
	int	ct;
	int	err;

	ct = 0;
	err = 0;
	while (pipes[ct + 1])
	{
		err = close(pipes[ct][0]);
		if (err == -1)
			print_error("Failed to close input side from a pipe", "");
		err = close(pipes[ct][1]);
		if (err == -1)
			print_error("Failed to close output side from a pipe", "");
		free(pipes[ct]);
		ct++;
	}
	free(pipes[ct]);
	free(pipes);
	return (err);
}

int	close_pipes(t_cmd *cmd, int **pipes)
{
	int	ct;
	int	err;

	ct = -1;
	err = 0;
	if (cmd == NULL)
		return (close_all(pipes));
	while (pipes[++ct + 2])
	{
		if (pipes[ct][0] != cmd->in)
			err = close(pipes[ct][0]);
		if (pipes[ct][1] != cmd->out)
			err = close(pipes[ct][1]);
		if (err != 0)
			return (-1);
		free(pipes[ct]);
	}
	if (pipes[ct][0] != cmd->in)
		err |= close(pipes[ct][0]);
	if (pipes[ct][1] != cmd->out)
		err |= close(pipes[ct][1]);
	free(pipes[ct]);
	free(pipes[ct + 1]);
	free(pipes);
	return (!err);
}

/**
 * Initiate all pipes we need to use for pipex.
 * Then add the file descriptors of the files used.
*/
int	**init_pipes(int size, int in, int out)
{
	int	**pipes;
	int	ct;

	pipes = malloc((size + 2) * sizeof(int *));
	if (pipes == NULL)
		print_error("", "Malloc error");
	pipes[size + 1] = NULL;
	ct = 0;
	while (ct < size)
	{
		pipes[ct] = malloc(2 * sizeof(int));
		if (pipes[ct] == NULL)
			return (free_pipes(pipes, ct, in, out));
		if (pipe((pipes[ct])) == -1)
			return (free_pipes(pipes, ct, in, out));
		ct++;
	}
	pipes[size] = malloc(2 * sizeof(int));
	if (pipes[size] == NULL)
		return (free_pipes(pipes, ct, in, out));
	pipes[size][0] = in;
	pipes[size][1] = out;
	return (pipes);
}

/// @brief The core of the program.
/// Create each process used and give them their respective command.
/// Then, launch each one.
/// @param cmds The array of commands parsed.
/// @param pipes The array of pipes used to transfer data.
/// @param argc The number of commands
/// @param env The array having environment variables
int	pipex(t_cmd **cmds, int **pipes, int argc, char **env)
{
	int		ct;
	t_proc	proc;

	ct = argc + 1;
	while (--ct > 0)
	{
		proc.pid = fork();
		if (proc.pid == -1)
			return (-1);
		if (proc.pid == 0)
		{
			init_proc(&proc, cmds[ct - 1], pipes, ct - 1);
			break ;
		}
	}
	if (ct == 0)
		proc.cmd = NULL;
	if (close_pipes(proc.cmd, pipes) == -1)
		print_error("Error while closing pipes.\n", "");
	if (proc.pid == 0)
		exec_cmd(proc.cmd, env, cmds);
	//free_cmds(cmds, argc);
	return (wait_childs(argc));
}
