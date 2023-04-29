/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:05:03 by ggiboury          #+#    #+#             */
/*   Updated: 2023/02/27 14:05:14 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	start_with(char *s, const char *s2)
{
	int	ct;
	int	ct2;
	int	ct3;

	ct = 0;
	while (s[ct])
	{
		ct2 = ct;
		ct3 = 0;
		while (s[ct2] && s2[ct3] && s[ct2] == s2[ct3])
		{
			ct2++;
			ct3++;
		}
		if (s2[ct3] == 0)
			return (1);
		ct++;
	}
	return (0);
}

char	**init_path(char **env)
{
	char	**path;
	int		ct;

	ct = 0;
	while (env[ct] != NULL)
	{
		if (start_with(env[ct], "PATH="))
			break ;
		ct++;
	}
	if (!start_with(env[ct], "PATH="))
		return (NULL);
	path = ft_split(env[ct] + 5, ':');
	return (path);
}

int	set_cmd(t_cmd *cmd, char **env)
{
	char	*cur;
	char	**path;
	int		ct;
	char	*tofree;

	ct = 0;
	path = init_path(env);
	while (path[ct] != NULL)
	{
		tofree = ft_append(path[ct], "/", 0);
		cur = ft_append(tofree, cmd->option[0], 0);
		free(tofree);
		if (access(cur, X_OK) == 0)
		{
			cmd->option[0] = cur;
			free_tab_str(path);
			return (1);
		}
		free(cur);
		errno = 0;
		ct++;
	}
	free_tab_str(path);
	if (access(cmd->option[0], X_OK) == 0)
		return (1);
	return (-1);
}
