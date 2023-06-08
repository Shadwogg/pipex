/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:05:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/08 15:19:47 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
/*
/// @brief The core of the program.
/// Create each process used and give them their respective command.
/// Then, launch each one.
/// @param cmds The array of commands parsed.
/// @param pipes The array of pipes used to transfer data.
/// @param argc The number of commands
/// @param env The array having environment variables
int	pipex_bonus(t_cmd **cmds, int **pipes, int argc, char **env)
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
}*/

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;
	int		**pipes;
	t_cmd	**cmds;

	if (argc < 5)
		print_error("Usage : ./pipex infile cmd1 ... cmdx outfile.\n", "");
	if (pipex_preparse(argc, argv, &in, &out) == -1)
		print_error("Parsing failed.", "");
	if (init_pipes(argc - 4, in, out, &pipes) == NULL)
		print_error("Pipes failed to be initialized.", "");
	cmds = init_cmd(argv, argc - 3, in, out);
	if (cmds == NULL)
	{
		free_pipes(pipes, argc - 3, in, out);
		print_error("Commands failed to be initialized.", "");
	}
	if (pipex(cmds, pipes, argc - 3, env) == -1)
	{
		free_cmds(cmds, argc - 2);
		free_pipes(pipes, argc - 3, in, out);
		print_error("One command didn't properly executed.", "");
	}
	free_cmds(cmds, argc - 4);
	return (0);
}
