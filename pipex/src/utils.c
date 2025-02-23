/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:00 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/23 15:08:52 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	find_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_path(char **cmd, char **paths, int *error)
{
	int		i;
	char	*exec;
	char	*current_path;

	i = 0;
	while (paths[i])
	{
		current_path = ft_strjoin(paths[i++], "/", error);
		if (!current_path)
			return (NULL);
		exec = ft_strjoin(current_path, cmd[0], error);
		free (current_path);
		if (!exec)
			return (NULL);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_split(paths);
			return (exec);
		}
		free(exec);
		exec = NULL;
	}
	return (NULL);
}

static int	is_executable_path(char **cmd)
{
	int	has_slash;
	int	has_dot;
	int	is_executable;

	has_slash = (ft_strchr(cmd[0], '/') != NULL);
	has_dot = (ft_strchr(cmd[0], '.') != NULL);
	is_executable = (access(cmd[0], F_OK | X_OK) == 0);
	return (has_slash && !has_dot && is_executable);
}

char	*find_path(char **cmd, char **envp, int *error)
{
	char	**paths;
	char	*exec;

	if (is_executable_path(cmd))
		return (ft_strdup(cmd[0]));
	if (find_line(envp) == -1)
		return (NULL);
	if (ft_strchr(cmd[0], '/'))
		return (*error = 2, NULL);
	paths = ft_split(envp[find_line(envp)] + 5, ':', error);
	if (!paths)
		return (NULL);
	exec = get_path(cmd, paths, error);
	if (exec)
		return (exec);
	ft_free_split(paths);
	return (NULL);
}
