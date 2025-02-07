/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:49:12 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/07 22:50:13 by vlopatin         ###   ########.fr       */
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
# define DIR	"Not a directory"
# define FORK	"Fork"
# define PIPE	"Pipe"
# define EXECVE	"Execve"

# define FATAL	1
# define NON_FATAL	0

typedef struct	s_pipe_side {
	int fd;
	char **cmd;
	char *path;
	pid_t	pid;
	int is_valid;
}	t_pipe_side;

void	close_free_left(t_pipe_side	*left);
void	close_free_right(t_pipe_side	*right);
void	pipe_fail(t_pipe_side	*left, t_pipe_side	*right);
void	fork_fail(t_pipe_side	*left, t_pipe_side	*right, int *pipe_fd);
void	close_fds(int fd1, int *fd2, int *fd3, int amount);
void	exit_error(int error, char ***arr1, char **arr2, const char *msg);
char	*find_path(char **cmd, char **envp);

#endif
