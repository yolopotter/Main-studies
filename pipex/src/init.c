/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:31:46 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/14 16:00:25 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_all(t_side *left, t_side *right)
{
	left->pipe_fd[0] = -1;
	left->pipe_fd[1] = -1;
	left->fd = -1;
	left->cmd = NULL;
	left->path = NULL;
	left->pid = -1;
	left->error = 0;
	left->is_valid = 0;
	right->pipe_fd[0] = -1;
	right->pipe_fd[1] = -1;
	right->fd = -1;
	right->cmd = NULL;
	right->path = NULL;
	right->pid = -1;
	right->error = 0;
	right->is_valid = 0;
}

void	init_left_side(t_side *left, char **av, char **envp)
{
	left->fd = open(av[1], O_RDONLY);
	if (left->fd == -1)
	{
		open_fail(left, NULL, av, LEFT);
		return ;
	}
	left->cmd = ft_split(av[2], ' ', &(left->error));
	if (!left->cmd || !left->cmd[0])
	{
		split_fail(left, NULL, left->error, LEFT);
		return ;
	}
	left->path = find_path(left->cmd, envp, &(left->error));
	if (!left->path)
	{
		path_fail(left, NULL, LEFT);
		return ;
	}
	left->is_valid = 1;
}

void	init_right_side(t_side *left, t_side *right, char **av, char **envp)
{
	right->fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (right->fd == -1)
		open_fail(left, right, av, RIGHT);
	right->cmd = ft_split(av[3], ' ', &(right->error));
	if (!right->cmd || !right->cmd[0])
		split_fail(left, right, right->error, RIGHT);
	right->path = find_path(right->cmd, envp, &(right->error));
	if (!right->path)
		path_fail(left, right, RIGHT);
}
