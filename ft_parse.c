/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:54:12 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/09 00:45:42 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_tab(char **str)
{
	int	ct;

	ct = 0;
	while (str[ct] != NULL)
	{
		printf("%s|\n", str[ct]);
		ct++;
	}
}

int	count_token(char *str)
{
	int	word;
	int	ct;

	word = 0;
	ct = 0;
	while (str[ct])
	{

		if (str[ct] == ' ')
			while (str[ct] == ' ')
				ct++;
		else if (str[ct] == 34)
			while (str[++ct] && str[ct] != 34)
				;
		else if (str[ct] == 39)
			while (str[++ct] && str[ct] != 39)
				;
		else
			while (str[ct] && str[ct] != 32 && str[ct] != 34 && str[ct] != 39)
				ct++;
		if (str[ct - 1] != ' ')
			word++;
	}
	return (word);
}

char	**pipex_split(char *str, char **arr)
{
	int		start;
	int		end;
	int		ct;
	char	limiter;

	start = 0;
	ct = 0;
	while (str[start])
	{
		while (str[start] == ' ')
			start++;
		end = start + 1;
		if (str[start] == 34 || str[start] == 39)
			limiter = str[start];
		else
			limiter = 32;
		while (str[++end] && str[end] != limiter)
			;
		if (str[end] == limiter)
			end++;
		arr[ct++] = ft_substr(str, start, end - start);
		if (arr[ct - 1] == NULL)
			return (NULL);
		start = end;
	}
	print_tab(arr);
	return (arr);
}

//awk '{count++} END {print count}'

char	**ft_pipex_split(char *str)
{
	char	*cur;
	int		ct;
	char	**arr;

	ct = 0;
	cur = str;
	while (*cur != 0)
	{
		if (*cur == 34 || *cur == 39)
			ct++;
		cur++;
	}
	if (ct > 0)
	{
		arr = malloc((count_token(str)) * sizeof(char *));
		arr[count_token(str) - 1] = NULL;
		return (pipex_split(str, arr));
	}
	return (ft_split(str, ' '));
}

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

	cmds = malloc((size + 1) * sizeof(t_cmd *));
	if (cmds == NULL)
		return (NULL);
	cmds[size] = NULL;
	ct = -1;
	while (++ct < size)
	{
		cmds[ct] = malloc(sizeof(t_cmd));
		if (cmds[ct] == NULL)
			return (free_cmds(cmds, ct));
		cmds[ct]->out = -1;
		cmds[ct]->in = -1;
		cmds[ct]->option = ft_pipex_split(argv[ct + 2]);
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
	return (1);
}
