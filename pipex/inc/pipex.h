/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:49:12 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/05 12:22:43 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h> //NULL
# include <unistd.h> //execve, fork
# include <fcntl.h> //pid_t
# include <stdio.h> //perror
# include <sys/wait.h> //wait

# define AC "Usage: ./pipex file1 cmd1 cmd2 file2"
# define PATH "Command not found in system files"
# define PATH1 "Command not found in system files: No such file or directory"
# define FORK "Fork"
# define PIPE "Pipe"
# define OPEN "Open"
# define EXECVE "Execve"

void	fork_fail(int *pipe_fd);
void	close_fds(int *fd, int amount);
void	exit_error(int error, char **arr1, char *arr2, const char *msg);
char	*find_path(char **cmd, char **envp);

#endif
