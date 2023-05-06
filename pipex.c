/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:39 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/03 16:39:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_pipes(t_cmd *cmd, int **pipes)
{
	int	ct;
	int	err;

	ct = 0;
	err = 0;
	while (pipes[ct + 2])
	{
		if (pipes[ct][0] != cmd->in)
			err |= close(pipes[ct][0]);
		if (pipes[ct][1] != cmd->out)
			err |= err | close(pipes[ct][1]);
		if (err != 0)
			return (-1);
		ct++;
	}
	if (pipes[ct][0] != cmd->in)
		err = close(pipes[ct][0]);
	if (pipes[ct][1] != cmd->out)
		err = err | close(pipes[ct][1]);
	return (1);
}

int	wait_childs(int *childs, int *status)
{
	int	ct;
	int	err;

	ct = 0;
	while (childs[ct] != -1)
	{
		err = waitpid(-childs[ct], status, 0);
		if (err == -1)
		{
			if (errno == ECHILD)
				break ;
			print_error();
		}
		if (! WIFEXITED(*status))
		{
			write_error("err\n");
			exit(EXIT_FAILURE);
		}
		ct++;
	}
	free(childs);
	return (1);
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
	int		*childs;
	t_proc	proc;

	childs = malloc((argc + 1) * sizeof(int));
	if (childs == NULL)
		return (-1);
	childs[argc--] = -1;
	while (argc >= 0)
	{
		proc.pid = fork();
		childs[argc] = proc.pid;
		if (proc.pid == -1)
			return (-1);
		errno = 0;
		if (proc.pid == 0)
		{
			init_proc(&proc, cmds[argc], pipes, argc);
			break ;
		}
		argc--;
	}
	if (proc.pid == 0)
	{
		close_pipes(proc.cmd, pipes);
		if (errno != 0)
			exit(EXIT_FAILURE);
		exec_cmd(proc.cmd, env);
	}
	return (wait_childs(childs, &(proc.status)));
}

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;
	int		**pipes;
	t_cmd	**cmds;

	if (argc != 5)
	{
		write_error("Usage : ./pipex <infile> <cmd 1> <cmd 2> <outfile>.\n");
		return (1);
	}
	if (pipex_preparse(argc, argv, &in, &out) == -1)
		exit(EXIT_FAILURE);
	pipes = init_pipes(argc - 4, in, out);
	cmds = init_cmd(argv, argc - 3, in, out);
	if (pipes == NULL || cmds == NULL)
		print_error();
	if (pipex(cmds, pipes, argc - 3, env) == -1)
		print_error();
	return (0);
}
