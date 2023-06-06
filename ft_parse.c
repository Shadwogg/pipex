/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:54:12 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/06 17:58:16 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief Initialize a t_cmd command.
/// @param argv The raw input from the user.
/// @param size The number of command.
/// @param in The fd corresponding to the input file.
/// @param out The fd corresponding to the output file.
/// @return The array of command.
t_cmd	**init_cmd(char **argv, int size, int in, int out)
{
	int		ct;
	t_cmd	**cmds;

	cmds = malloc((size + 1) * sizeof(t_cmd));
	if (cmds == NULL)
		return (NULL);
	cmds[size] = NULL;
	ct = 0;
	while (ct < size)
	{
		cmds[ct] = malloc(sizeof(t_cmd));
		if (cmds[ct] == NULL)
			return (free_cmds(cmds, ct));
		cmds[ct]->out = -1;
		cmds[ct++]->in = -1;
		cmds[ct]->option = ft_split(argv[ct + 2], ' ');
		if (cmds[ct]->option == NULL)
		{
			free(cmds[ct]);
			return (free_cmds(cmds, ct));
		}
	}
	cmds[0]->in = in;
	cmds[ct - 1]->out = out;
	return (cmds);
}

int	init_proc(t_proc *proc, t_cmd *cmd, int **pipe, int p)
{
	proc->cmd = cmd;
	if (proc->cmd->in == -1 && proc->cmd->out == -1)
	{
		proc->cmd->in = pipe[p][0];
		proc->cmd->out = pipe[p][1];
	}
	else if (proc->cmd->in == -1)
		proc->cmd->in = pipe[p - 1][0];
	else if (proc->cmd->out == -1)
		proc->cmd->out = pipe[p][1];
	else
		return (-1);
	return (1);
}

/**
 * Set p to the file descriptor corresponding to the file if we can read from it.
*/
int	ft_open(char *file_in, int *fd)
{
	if (file_in == NULL || access(file_in, R_OK) == -1)
	{
		perror(file_in);
		exit(EXIT_FAILURE);
	}
	*fd = open(file_in, O_RDONLY | O_CLOEXEC);
	if (*fd == -1)
	{
		perror(file_in);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * Try to open in and out then return if we can read from the input file
 * and create the output file
*/
int	pipex_preparse(int argc, char **argv, int *in, int *out)
{
	if (!access(argv[argc - 1], F_OK))
		if (unlink(argv[argc - 1]) != 0)
			print_error("", "unlink error");
	*out = open(argv[argc - 1], O_CREAT | O_RDWR | O_CLOEXEC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (*out == -1)
		print_error("", "open error");
	ft_open(argv[1], in);
	errno = 0;
	return (1);
}
