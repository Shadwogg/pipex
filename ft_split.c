/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:40:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/02/23 23:10:57 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_word(char *s, char del)
{
	char	*str;
	int		ct;

	ct = 0;
	while (s[ct] && s[ct] != del)
		ct++;
	str = malloc((ct + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[ct] = 0;
	while (--ct >= 0)
		str[ct] = s[ct];
	return (str);
}

int	get_number_words(char *s, char del)
{
	int	number;
	int	ct;

	ct = 0;
	number = 0;
	while (s[ct])
	{
		while (s[ct] && s[ct] != del)
			ct++;
		number++;
		while (s[ct] == del)
			ct++;
	}
	return (number);
}

char	**ft_split(char *s, char del)
{
	char	**tab;
	int		ct;
	int		ct2;

	if (s == ((void *) 0))
		return (NULL);
	tab = malloc((get_number_words(s, del) + 1) * sizeof(char *));
	if (tab == (NULL))
		return (tab);
	tab[get_number_words(s, del)] = NULL;
	ct = 0;
	ct2 = 0;
	while (s[ct])
	{
		tab[ct2] = get_next_word(s + ct, del);
		if (tab[ct2] == NULL)
			return (free_n_tab(tab, ct2));
		while (s[ct] && s[ct] != del)
			ct++;
		if (s[ct])
			ct++;
		ct2++;
	}
	return (tab);
}
