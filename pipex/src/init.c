/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:31:46 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/21 16:23:33 by vlopatin         ###   ########.fr       */
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
		return (open_fail(left, NULL, av, LEFT), (void)0);
	left->cmd = ft_split(av[2], ' ', &(left->error));
	if (!left->cmd && left->error == 1)
		return (split_fail(left, NULL, 1, LEFT), (void)0);
	else if (!left->cmd[0] && av[2][0] == '\0')
		return (split_fail(left, NULL, 2, LEFT), (void)0);
	else if (!left->cmd[0])
		return (split_fail(left, NULL, 3, LEFT), (void)0);
	left->path = find_path(left->cmd, envp, &(left->error));
	if (!left->path)
		return (path_fail(left, NULL, LEFT), (void)0);
	left->is_valid = 1;
}

void	init_right_side(t_side *left, t_side *right, char **av, char **envp)
{
	right->fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (right->fd == -1)
		open_fail(left, right, av, RIGHT);
	right->cmd = ft_split(av[3], ' ', &(right->error));
	if (!right->cmd && right->error == 1)
		split_fail(left, right, 1, RIGHT);
	else if (!right->cmd[0] && av[3][0] == '\0')
		split_fail(left, right, 2, RIGHT);
	else if (!right->cmd[0])
		split_fail(left, right, 3, RIGHT);
	right->path = find_path(right->cmd, envp, &(right->error));
	if (!right->path)
		path_fail(left, right, RIGHT);
}
