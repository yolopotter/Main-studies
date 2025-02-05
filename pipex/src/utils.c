/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:00 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/05 16:06:50 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	fork_fail(int *pipe_fd)
{
	close_fds(pipe_fd, 2);
	exit_error(2, NULL, NULL, FORK);
}

void	close_fds(int *fd, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (fd[i] != -1)
			close (fd[i]);
		fd[i] = -1;
		i++;
	}
}
// exit(42) exists because when ft_split returns NULL, perror would print Success.

void	exit_error(int error, char **arr1, char *arr2, const char *msg)
{
	if (error == 1)
		ft_putendl_fd((char *)msg, 2);
	if (error == 2)
		perror((char *)msg);
	if (error == 3 || error ==4)
	{
		ft_free_split(arr1);
		free(arr2);
		perror((char *)msg);
		if (error == 3)
			exit (127);
		else if (error == 4)
			exit (1);
	}
	if (error == 5)
	{
		ft_free_split(arr1);
		exit(42);
	}
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
	exit_error(3, cmd, NULL, PATH);
	return (NULL);
}
