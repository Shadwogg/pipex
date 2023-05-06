/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:30:22 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 22:29:34 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Set the memory to 0 until we encounter a line break
*/
void	gnl_bzero(char *buffer)
{
	int	ct;

	ct = 0;
	if (ct < BUFFER_SIZE && buffer[ct] == '\n')
	{
		buffer[ct] = 0;
		return ;
	}
	while (ct < BUFFER_SIZE && buffer[ct] != '\n')
		buffer[ct++] = 0;
	if (ct < BUFFER_SIZE && buffer[ct] == '\n')
		buffer[ct] = 0;
}

/**
 * Free the memory
*/
void	*gnl_free(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

/**
 * Test whether a buffer contain some characters.
*/
int	ft_is_filled(char *buf)
{
	int	ct;

	ct = 0;
	while (ct < BUFFER_SIZE)
	{
		if (buf[ct] != 0)
			return (1);
		ct++;
	}
	return (0);
}

/**
 * Test whether the string we are producing is finished.
*/
int	ft_is_finished(char *s, int size_str, int len_read)
{
	int	ct;

	ct = size_str - len_read;
	if (ct < 0)
		ct = 0;
	while (ct < size_str)
	{
		if (s[ct] == '\n')
			return (1);
		ct++;
	}
	return (0);
}

/**
 * Copy from src to dst max(n, space left) characters.
 * If n = -1, then it copies everything from src to dst.
*/
void	ft_strncpy(char *dst, char *src, int n)
{
	int	ct;

	ct = 0;
	if (n >= 0)
	{
		while (ct < n)
		{
			(dst)[ct] = src[ct];
			ct++;
		}
		return ;
	}
	ct--;
	while (src[++ct])
		(dst)[ct] = src[ct];
}
