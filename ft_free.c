/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:09:41 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/05 16:04:07 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Free the array of the commands
*/
t_cmd	**free_cmds(t_cmd **tab)
{
	int	s;

	s = 0;
	while (tab + s != 0)
	{
		free_tab_str((*tab)->option);
		free(tab + s++);
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
int	**free_tab_pipes(int **tab, int size, int in, int out)
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
