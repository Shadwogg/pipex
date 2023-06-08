/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:39 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/08 15:02:40 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;
	int		**pipes;
	t_cmd	**cmds;

	if (argc != 5)
		print_error("Usage : ./pipex infile cmd1 cmd2 outfile.\n", "");
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
		free_cmds(cmds, argc - 4);
		free_pipes(pipes, argc - 3, in, out);
		print_error("One command didn't properly executed.", "");
	}
	free_cmds(cmds, argc - 4);
	return (0);
}
