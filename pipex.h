/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:34 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/04 14:57:16 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

//# include "get_next_line.h"

/* 
 * s_cmd stores everything we need to know to execute a command.
 *		- option is the path of the cmd and the arguments.
		- err stores the message of error
 *		- in stores the file descriptor of the input, or is NULL.
 *		- out stores the file descriptor of the output, or is NULL.
 * if input or output is NULL, it means we have to read/write from
 * the standard in/output
 */
typedef struct s_cmd{
	char	**option;
	int		in;
	int		out;
}	t_cmd;

/*
 * s_proc stores everything we need to use 
 * to execute a command for a given processus.
 *		- pid is the pid of the processus.
 *		- status is used for wait() and waitpid().
 *		- cmd is the command the proc should execute.
 */
typedef struct s_proc{
	pid_t			pid;
	int				status;
	struct s_cmd	*cmd;
}	t_proc;

char	*ft_append(char *s1, char *s2, char sep);
int		exec_cmd(t_cmd *cmd, char **env);
char	**free_tab_str(char **tab);
t_cmd	**free_cmds(t_cmd **tab);
char	**free_n_tab(char **tab, size_t n);
int		**free_tab_pipes(int **tab, int size, int in, int out);
t_cmd	**init_cmd(char **argv, int size, int in, int out);
int		**init_pipes(int size, int in, int out);
int		init_proc(t_proc *proc, t_cmd *cmd, int **pipe, int p);
int		pipex_preparse(int argc, char **argv, int *in, int *out);
int		print_error(char *str);
int		get_tab_len(char **param);
int		set_cmd(t_cmd *cmd, char **env);
char	**ft_split(char *s, char del);
int		get_str_len(char *str);
void	write_error(char *msg);

void	ft_print_tab(t_cmd **cmd);

#endif