/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:30:10 by ggiboury          #+#    #+#             */
/*   Updated: 2023/02/02 15:47:06 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Refresh the buffer.
int	ft_op_buffer(char *buf)
{
	int	len;
	int	start;

	len = 0;
	start = 0;
	while (buf[start] == 0 && start < BUFFER_SIZE)
		start++;
	while (start < BUFFER_SIZE)
		buf[len++] = buf[start++];
	start = len;
	while (start < BUFFER_SIZE)
		buf[start++] = 0;
	if (len < BUFFER_SIZE)
		buf[len] = 0;
	return (len);
}

// Fill the buffer with what is on fd,
// then return the length of what we should copy.
int	ft_read(int fd, char *buf)
{
	int	len;

	if (ft_is_filled(buf))
		len = ft_op_buffer(buf);
	else
		len = read(fd, buf, BUFFER_SIZE);
	if (len == -1 || len == 0)
		return (len);
	len = 0;
	while (len < BUFFER_SIZE && buf[len] != '\n' && buf[len])
		len++;
	if (len < BUFFER_SIZE && buf[len] == '\n')
		len++;
	return (len);
}

// Add the buffer at the end of dst.
// len_read is the number of character that we must add
int	gnl_append(char **dst, char *buffer, int len_read, int *size_str)
{
	char	*cpy;

	cpy = *dst;
	*dst = malloc((*size_str + 1 + len_read) * sizeof(char));
	if (*dst == NULL)
	{
		gnl_free(cpy);
		gnl_free(*dst);
		return (-1);
	}
	ft_strncpy(*dst, cpy, -1);
	ft_strncpy((*dst + (*size_str)), buffer, len_read);
	(*dst)[(*size_str) + len_read] = 0;
	*size_str += len_read;
	gnl_free(cpy);
	return (0);
}

// Returns the next line read from file descriptor
char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE];
	int			len_read;
	int			size_str;

	len_read = ft_read(fd, buffer);
	if (len_read == -1 || len_read == 0)
		return (NULL);
	str = malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = 0;
	size_str = 0;
	while (!ft_is_finished(str, size_str, len_read))
	{
		len_read = ft_read(fd, buffer);
		if (len_read == -1)
			return (gnl_free(str));
		if (len_read == 0)
			return (str);
		if (gnl_append(&str, buffer, len_read, &size_str) == -1)
			return (gnl_free(str));
		gnl_bzero(buffer);
	}
	return (str);
}
