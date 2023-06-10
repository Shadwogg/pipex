/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:29:42 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/10 16:34:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**pipex_split(char *str, char **arr, int start)
{
	int		end;
	int		ct;
	char	limiter;

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
	return (arr);
}

char	**ft_pipex_split(char *str)
{
	char	*cur;
	int		ct;
	int		start;
	char	**arr;

	ct = 0;
	cur = str;
	start = 0;
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
		return (pipex_split(str, arr, start));
	}
	return (ft_split(str, ' '));
}
