/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:55:38 by ggiboury          #+#    #+#             */
/*   Updated: 2023/02/02 15:46:25 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// For get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Libft prototypes
*/

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t size);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int x);
int		ft_isalpha(int x);
int		ft_isascii(int x);
int		ft_isdigit(int x);
int		ft_isprint(int x);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t size);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *c, int fd);

/**
 * Libft_bonus prototypes
*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * Printf prototypes
*/
int		ft_end(va_list *ptr);
int		ft_get_size(long x);
int		ft_get_size_hex(unsigned int x);
int		ft_get_size_hexptr(unsigned long x);
int		ft_good_format(char *str);
int		ft_isvalid_str(const char *str);
int		ft_is_in(char c, char *set);
int		ft_put_hexnbr(unsigned int x, int is_cap);// icici
int		ft_printf(const char *str, ...);
int		ft_print_arg(char c, va_list lst);
int		ft_print_hexnbr(unsigned int x, int is_cap);
int		ft_print_hexptr(unsigned long x);
int		ft_print_nbr(long x);
int		ft_print_pointer(void *x);

/**
 * Get_next_line prototypes
*/
int		gnl_append(char **dst, char *buffer, int len_read, int *size_str);
void	gnl_bzero(char *buffer);
void	*gnl_free(char *str);
int		ft_is_filled(char *buf);
int		ft_is_finished(char *s, int size_str, int len_read);
int		ft_op_buffer(char *buf);
int		ft_read(int fd, char *buf);
void	ft_strncpy(char *dst, char *src, int n);
char	*get_next_line(int fd);

#endif
