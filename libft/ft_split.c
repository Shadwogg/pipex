/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:40:02 by ggiboury          #+#    #+#             */
/*   Updated: 2022/11/17 19:09:53 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_nb_word(const char *s, char c)
{
	int	ct;
	int	word;

	ct = 0;
	word = 0;
	while (s[ct])
	{
		while (s[ct] == c)
			ct++;
		if (s[ct] != 0 && s[ct] != c)
		{
			while (s[ct] != c && s[ct] != 0)
				ct++;
			word++;
		}
	}
	return (word);
}

static void	ft_free_tab(char **tab, size_t n)
{
	while (n > 0)
	{
		free(tab[n]);
		n--;
	}
	free(tab[0]);
	free(tab);
}

static int	ft_split2(char **tab, int word, const char *s, char c)
{
	int		start;
	int		end;

	start = 0;
	while (word < ft_get_nb_word(s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		end = start + 1;
		while (s[end] && s[end] != c)
			end++;
		tab[word] = ft_substr(s, start, end - start);
		if (tab[word] == NULL)
		{
			ft_free_tab(tab, word);
			return (1);
		}
		start = end;
		while (s[start] && s[start] == c)
			start++;
		word++;
	}
	tab[word] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;

	if (s == NULL)
		return (NULL);
	tab = malloc((ft_get_nb_word(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	word = 0;
	if (ft_split2(tab, word, s, c))
		return (NULL);
	return (tab);
}
