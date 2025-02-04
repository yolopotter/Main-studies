/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:00 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/04 12:04:49 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exit_error(int error, char **arr1, char *arr2, const char *msg)
{
	if (error == 1)
		ft_putendl_fd((char *)msg, 2);
	if (error == 2)
		perror((char *)msg);
	if (error == 3)
	{
		ft_free_split(arr1);
		free(arr2);
		perror((char *)msg);
	}
	exit(1);
}

char	**parse_cmd(char *av)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	return (cmd);
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
	char	*tmp;
	char	*exec;

	i = find_line(envp);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(paths[i], cmd[0]);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		exec = NULL;
		i++;
	}
	exit_error(3, cmd, NULL, PATH);
	return (paths[i]);
}
