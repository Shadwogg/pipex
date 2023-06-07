/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:28:34 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/07 22:20:54 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"

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
int		ft_open(char *file_in, int *fd);
int		exec_cmd(t_cmd *cmd, char **env, t_cmd **cmds);

t_cmd	**init_cmd(char **argv, int size, int in, int out);
int		init_proc(t_proc *proc, t_cmd *cmd, int **pipe, int p);
int		pipex(t_cmd **cmds, int **pipes, int argc, char **env);
int		pipex_preparse(int argc, char **argv, int *in, int *out);
int		print_error(char *desc, char *err);
int		get_tab_len(char **param);
int		set_cmd(t_cmd *cmd, char **env);
int		wait_childs(int number);

// FREE
char	**free_tab_str(char **tab);
t_cmd	**free_cmds(t_cmd **tab, int ct);
t_cmd	**free_cmd(t_cmd **tab, t_cmd *cmd);
char	**free_n_tab(char **tab, size_t n);
int		**free_pipes(int **tab, int size, int in, int out);

// PIPES
int		close_all(int **pipes);
int		close_pipes(t_cmd *cmd, int **pipes);
int		**init_pipes(int size, int in, int out);

#endif