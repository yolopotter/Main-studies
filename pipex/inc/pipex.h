/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:49:12 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/07 15:08:30 by vlopatin         ###   ########.fr       */
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
# define OPEN	"Open"
# define EXECVE	"Execve"

# define FATAL	1
# define NON_FATAL	0

typedef struct	s_pipe_side {
	int fd;
	char **cmd;
	char *path;
	int is_valid;
}	t_pipe_side;

void	pipe_fail(int *fd, char **cmd1, char **cmd2);
void	fork_fail(int *fd, int *pipe_fd, char **cmd1, char **cmd2);
void	close_fds(int *fd1, int *fd, int amount);
void	exit_error(int error, char **arr1, char *arr2, const char *msg);
char	*find_path(char **cmd, char **envp, int fatal);

#endif
