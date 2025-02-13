/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/13 16:12:45 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	child_process1(t_side *left, t_side *right, char **envp)
{
	left->pid = fork();
	if (left->pid == -1)
		fork_fail(left, right);
	if (left->pid == 0)
	{
		close_fds(&(right->pipe_fd[0]), NULL, NULL, 0);
		close_fds(&(right->fd), NULL, NULL, 0);
		dup2(left->fd, STDIN_FILENO);
		dup2(right->pipe_fd[1], STDOUT_FILENO);
		close_fds(&(left->fd), NULL, NULL, 0);
		close_fds(&(right->pipe_fd[1]), NULL, NULL, 0);
		execve(left->path, left->cmd, envp);
		exit_error_3(6, &(left->cmd), left, right);
	}
}

static void	child_process2(t_side *left, t_side *right, char **envp)
{
	right->pid = fork();
	if (right->pid == -1)
		fork_fail(left, right);
	if (right->pid == 0)
	{
		close_fds(&(right->pipe_fd[1]), NULL, NULL, 0);
		close_fds(&(left->fd), NULL, NULL, 0);
		dup2(right->pipe_fd[0], STDIN_FILENO);
		dup2(right->fd, STDOUT_FILENO);
		close_fds(&(right->pipe_fd[0]), NULL, NULL, 0);
		close_fds(&(right->fd), NULL, NULL, 0);
		execve(right->path, right->cmd, envp);
		exit_error_3(6, &(right->cmd), left, right);
	}
}

static void	parent_process(t_side *left, t_side *right)
{
	int	status;

	status = 0;
	close_fds(NULL, right->pipe_fd, NULL, 2);
	waitpid(left->pid, NULL, 0);
	waitpid(right->pid, &status, 0);
	close_free_left(left);
	close_free_right(right);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
}

// check for leaks when pipe fails, fork fails,

int	main(int ac, char **av, char **envp)
{
	t_side	left;
	t_side	right;

	if (ac != 5)
		exit_error(1, NULL, AC2);
	init_all(&left, &right);
	init_left_side(&left, av, envp);
	if (pipe(right.pipe_fd) == -1)
		pipe_fail(&left, &right);
	if (left.is_valid)
	{
		child_process1(&left, &right, envp);
		waitpid(left.pid, NULL, WNOHANG);
	}
	else if (left.fd != -1)
		dup2(left.fd, STDIN_FILENO);
	init_right_side(&left, &right, av, envp);
	child_process2(&left, &right, envp);
	parent_process(&left, &right);
	return (0);
}
