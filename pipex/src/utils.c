/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:00 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/07 23:42:55 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipe_fail(t_pipe_side	*left, t_pipe_side	*right)
{
	close_free_left(left);
	close_free_right(right);
	exit_error(2, NULL, NULL, PIPE);
}

void	fork_fail(t_pipe_side	*left, t_pipe_side	*right, int *pipe_fd)
{
	close_fds(-1, NULL, pipe_fd, 2);
	close_free_left(left);
	close_free_right(right);
	exit_error(2, NULL, NULL, FORK);
}

void	close_fds(int fd1, int *fd2, int *fd3, int amount)
{
	int	i;

	i = 0;
	while (i < amount && fd3)
	{
		if (fd3[i] != -1)
			close (fd3[i]);
		fd3[i] = -1;
		i++;
	}
	i = 0;
	while (i < amount && fd2)
	{
		if (fd2[i] != -1)
			close (fd2[i]);
		fd2[i] = -1;
		i++;
	}
	if (fd1 != -1)
	{
		close(fd1);
		fd1 = -1;
	}
}

void	exit_error(int error, char ***arr1, char **arr2, const char *msg)
{
	ft_putstr_fd(PIPEX, 2);
	if (error == 1) // amount of argument error
	{
		ft_putendl_fd(AC1, 2);
		ft_putendl_fd((char *)msg, 2);
	}
	if (error == 2) //pipe or fork creation error
	{
		perror((char *)msg);
	}
	if (error == 3) //command not found error
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putendl_fd((*arr1)[0], 2);
		ft_free_split(*arr1);
		arr1 = NULL;
		exit (127);
	}
	if (error == 4) //file opening error
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
	if (error == 5) //command is NULL error
	{
		ft_putendl_fd(PATH1, 2);
		exit(127);
	}
	if (error == 6)
	{
		perror(EXECVE);
		ft_free_split(*arr1);
		free(arr2);
	}
	if (error == 13) //command not found error
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putendl_fd((*arr1)[0], 2);
	}
	if (error == 14) //file opening error
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
	if (error == 15) //command is NULL error
	{
		ft_putendl_fd(PATH1, 2);
	}
	if (error < 10)
		exit(1);
}

int	find_line(char **envp)
{
	int	i;

	i = 0;
	while (*envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
		i++;
	}
	return (i);
}

char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*exec;
	char	*current_path;

	i = find_line(envp);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		current_path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(current_path, cmd[0]);
		free (current_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_split(paths);
			return (exec);
		}
		free(exec);
		exec = NULL;
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}
