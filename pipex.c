/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:39 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/05 16:42:49 by ggiboury         ###   ########.fr       */
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
		ct++;
	}
	return (err);
}

int	close_pipes(t_cmd *cmd, int **pipes)
{
	int	ct;
	int	err;

	ct = 0;
	err = 0;
	if (cmd == NULL)
		return (close_all(pipes));
	while (pipes[ct + 2])
	{
		if (pipes[ct][0] != cmd->in)
			err = close(pipes[ct][0]);
		if (pipes[ct][1] != cmd->out)
			err = close(pipes[ct][1]);
		if (err != 0)
			return (-1);
		ct++;
	}
	if (pipes[ct][0] != cmd->in)
		err = close(pipes[ct][0]);
	if (pipes[ct][1] != cmd->out)
		err = close(pipes[ct][1]);
	return (1);
}

int	wait_childs(int number)
{
	int	err;
	int	status;

	status = 0;
	err = 0;
	while (number > 0)
	{
		err = waitpid(-1, &status, WNOHANG);
		if (err == -1)
			print_error("waitpid failed", "");
		if (!WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
				exit(WEXITSTATUS(status));
			print_error("child didnt quit normally\n", "");
		}
		number--;
	}
	return (err);
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

	ct = argc;
	while (ct >= 0)
	{
		proc.pid = fork();
		if (proc.pid == -1)
			return (-1);
		errno = 0;
		if (proc.pid == 0)
		{
			init_proc(&proc, cmds[ct], pipes, ct);
			break ;
		}
		ct--;
	}
	if (ct == -1)
		proc.cmd = NULL;
	if (close_pipes(proc.cmd, pipes) == -1)
		print_error("Error while closing pipes.\n", "");
	if (proc.pid == 0)
		exec_cmd(proc.cmd, env);
	return (wait_childs(argc));
}

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;
	int		**pipes;
	t_cmd	**cmds;

	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex <infile> <cmd 1> <cmd 2> <outfile>.\n", 1);
		return (1);
	}
	if (pipex_preparse(argc, argv, &in, &out) == -1)
		exit(EXIT_FAILURE);
	pipes = init_pipes(argc - 4, in, out);
	cmds = init_cmd(argv, argc - 3, in, out);
	if (pipes == NULL || cmds == NULL)
		print_error("Error while creating/initializing the pipes/cmds.", "");
	if (pipex(cmds, pipes, argc - 3, env) == -1)
		print_error("One command didn't properly executed.", "");
	return (0);
}
