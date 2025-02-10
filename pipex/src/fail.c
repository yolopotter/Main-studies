/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:20:36 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/10 19:27:33 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	path_fail(t_side	*left, t_side	*right, int side)
{
	if (side == LEFT)
	{
		if (left->error)
		{
			close_free_left(left);
			exit_error(4, NULL, NULL, MALLOC);
		}
		print_error(13, &(left->cmd), PATH);
		close_free_left(left);
	}
	if (side == RIGHT)
	{
		close_free_left(left);
		close_fds(right->fd, NULL, NULL, 0);
		if (right->error)
			exit_error(4, NULL, NULL, MALLOC);
		exit_error(3, &(right->cmd), NULL, PATH);
	}
}

void	split_fail(t_side	*left, t_side	*right, int error, int side)
{
	if (side == LEFT)
	{
		close_fds(left->fd, NULL, NULL, 0);
		if (error)
			exit_error(4, NULL, NULL, MALLOC);
		print_error(15, NULL, NULL);
	}
	if (side == RIGHT)
	{
		close_free_left(left);
		close_free_right(right);
		if (error)
			exit_error(4, NULL, NULL, MALLOC);
		exit_error(5, NULL, NULL, NULL);
	}
}

void	open_fail(t_side	*left, char **av, int side)
{
	if (side == LEFT)
		print_error(14, NULL, av[1]);
	if (side == RIGHT)
	{
		close_free_left(left);
		exit_error(4, NULL, NULL, av[4]);
	}
}

void	pipe_fail(t_side	*left, t_side	*right)
{
	close_free_left(left);
	close_free_right(right);
	exit_error(2, NULL, NULL, PIPE);
}

void	fork_fail(t_side	*left, t_side	*right, int *pipe_fd)
{
	close_fds(-1, NULL, pipe_fd, 2);
	close_free_left(left);
	close_free_right(right);
	exit_error(2, NULL, NULL, FORK);
}
