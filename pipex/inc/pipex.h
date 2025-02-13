/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:49:12 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/13 14:34:40 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h> //NULL
# include <unistd.h> //execve, fork
# include <fcntl.h> //pid_t
# include <stdio.h> //perror
# include <sys/wait.h> //waitpid

# define PIPEX	"pipex: "
# define AC1	"Incorrect amount of arguments"
# define AC2	"Usage: ./pipex file1 cmd1 cmd2 file2"
# define PATH	"Command not found: "
# define PATH1	"Permission denied:"
# define FILE	"No such file or directory: "
# define DIR	"Is a directory"
# define FORK	"Fork"
# define PIPE	"Pipe"
# define EXECVE	"Execve"
# define MALLOC	"Memory allocation failure"

# define LEFT	0
# define RIGHT	1

typedef struct s_side
{
	int		fd;
	char	**cmd;
	char	*path;
	pid_t	pid;
	int		error;
	int		is_valid;
	int		pipe_fd[2];
}	t_side;

// error handling
void	close_free_left(t_side *left);
void	close_free_right(t_side *right);
void	close_fds(int *fd1, int *fd2, int *fd3, int amount);
void	print_error(int error, char ***arr1, const char *msg);
void	exit_error(int error, char ***arr1, const char *msg);
void	exit_error_3(int error, char ***arr1, t_side *left, t_side *right);

// failures
void	open_fail(t_side *left, t_side *right, char **av, int side);
void	pipe_fail(t_side *left, t_side *right);
void	fork_fail(t_side *left, t_side *right);
void	split_fail(t_side *left, t_side *right, int error, int side);
void	path_fail(t_side *left, t_side *right, int side);

// init
void	init_all(t_side *left, t_side *right);
void	init_left_side(t_side *left, char **av, char **envp);
void	init_right_side(t_side *left, t_side *right, char **av, char **envp);

// utils
char	*find_path(char **cmd, char **envp, int *error);

#endif
