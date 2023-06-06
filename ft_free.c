/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:09:41 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/06 17:35:19 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Free the array of the commands
*/
t_cmd	**free_cmds(t_cmd **tab, int last)
{
	while (--last >= 0)
	{
		if (tab[last]->in != -1 && tab[last]->in != 0)
			close(tab[last]->in);
		if (tab[last]->out != -1 && tab[last]->out != 1)
			close(tab[last]->out);
		free_tab_str(tab[last]->option);
		free(tab[last]);
	}
	free(tab);
	return (NULL);
}

/**
 * Free n elements of the array of string tab
*/
char	**free_n_tab(char **tab, size_t n)
{
	while (n > 0)
	{
		free(tab[n]);
		n--;
	}
	free(tab[0]);
	free(tab);
	return (NULL);
}

/**
 * Free the array of string
*/
char	**free_tab_str(char **tab)
{
	int	s;

	s = 0;
	while (tab[s] != NULL)
		free(tab[s++]);
	free(tab);
	return (NULL);
}

/**
 * Free the array of pipes and close the fd used
*/
int	**free_pipes(int **tab, int size, int in, int out)
{
	int	ct;

	ct = 0;
	while (ct < size)
	{
		close(tab[ct][0]);
		close(tab[ct][1]);
		free(tab[ct++]);
	}
	free(tab);
	close(in);
	close(out);
	return (NULL);
}
