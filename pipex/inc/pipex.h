/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:49:12 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/04 12:02:40 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h> //NULL
# include <unistd.h> //execve, fork
# include <fcntl.h> //pid_t
# include <stdio.h> //printf
# include <sys/wait.h> //wait

# define AC "Usage: ./pipex file1 cmd1 cmd2 file2"
# define PATH "Command not found in system files"
# define FORK "Fork"
# define PIPE "Pipe"
# define OPEN "Open"
# define EXECVE "Execve"

void	exit_error(int error, char **arr1, char *arr2, const char *msg);
char	**parse_cmd(char *av);
char	*find_path(char **cmd, char **envp);

#endif
