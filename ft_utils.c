/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:14:59 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/05 17:28:11 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_tab_len(char **param)
{
	int	size;

	if (param == NULL || *param == NULL)
		return (0);
	size = 0;
	while (*(param++))
		size++;
	return (size);
}

char	*ft_append(char *s1, char *s2, char sep)
{
	int		ct;
	int		ct2;
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ct = -1;
	while (s1[++ct])
		str[ct] = s1[ct];
	if (sep != 0)
		str[ct++] = sep;
	ct2 = -1;
	while (s2[++ct2])
		str[ct + ct2] = s2[ct2];
	str[ct + ct2] = 0;
	return (str);
}

int	print_error(char *desc, char *err)
{
	if (desc != NULL)
		ft_putstr_fd(desc, 2);
	if (errno != 0)
		perror(err);
	exit(EXIT_FAILURE);
}
