/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/07 23:05:10 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(t_pipe_side	*left, t_pipe_side	*right, int *pipe_fd, char **envp)
{
	close(pipe_fd[0]);
	close(right->fd);
	dup2(left->fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(left->fd);
	close(pipe_fd[1]);
	if (execve(left->path, left->cmd, envp) == -1)
		exit_error(6, &(left->cmd), &(left->path), EXECVE);
}

void	child_process2(t_pipe_side	*left, t_pipe_side	*right, int *pipe_fd, char **envp)
{
	close(pipe_fd[1]);
	close(left->fd);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(right->fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(right->fd);
	if (execve(right->path, right->cmd, envp) == -1)
		exit_error(6, &(right->cmd), &(right->path), EXECVE);
}

void	parent_process(t_pipe_side	*left, t_pipe_side	*right, int *pipe_fd)
{
	int	status1;
	int	status2;

	close_fds(-1, pipe_fd, NULL, 2);
	close_free_left(left);
	close_free_right(right);
	waitpid(left->pid, &status1, 0);
	waitpid(right->pid, &status2, 0);
}

void	init_all(t_pipe_side	*right, t_pipe_side	*left, int *pipe_fd)
{
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	left->fd = -1;
	left->cmd = NULL;
	left->path = NULL;
	left->pid = -1;
	right->fd = -1;
	right->cmd = NULL;
	right->path = NULL;
	right->pid = -1;
}

void	close_free_left(t_pipe_side	*left)
{
	close_fds(left->fd, NULL, NULL, 0);
	left->fd = -1;
	ft_free_split(left->cmd);
	left->cmd = NULL;
	free(left->path);
	left->path = NULL;
}

void	close_free_right(t_pipe_side	*right)
{
	close_fds(right->fd, NULL, NULL, 0);
	right->fd = -1;
	ft_free_split(right->cmd);
	right->cmd = NULL;
	free(right->path);
	right->path = NULL;
}
void	init_left_side(t_pipe_side	*left, char **av, char **envp)
{
	left->fd = open(av[1], O_RDONLY);
	if (left->fd == -1)
	{
		exit_error(14, NULL, NULL, av[1]);
		return ;
	}
	left->cmd = ft_split(av[2], ' ');
	if (!left->cmd[0])
	{
		close_fds(left->fd, NULL, NULL, 0);
		exit_error(15, NULL, NULL, NULL);
		return ;
	}
	left->path = find_path(left->cmd, envp);//send original, not copy
	if (!left->path)
	{
		exit_error(13, &(left->cmd), NULL, PATH);
		close_free_left(left);
		return ;
	}
	left->is_valid = 1;
}

int	init_right_side(t_pipe_side	*right, t_pipe_side	*left, char **av, char **envp)
{
	right->fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (right->fd == -1)
	{
		close_free_left(left);
		exit_error(4, NULL, NULL, av[4]);
	}
	right->cmd = ft_split(av[3], ' ');
	if (!right->cmd[0])
	{
		close_free_left(left);
		close_free_right(right);
		exit_error(5, NULL, NULL, NULL);
	}
	right->path = find_path(right->cmd, envp);
	if (!right->path)
	{
		close_free_left(left);
		close_fds(right->fd, NULL, NULL, 0);
		exit_error(3, &(right->cmd), NULL, PATH);
	}
	return (1);
}

// check fd closures at different fails
//absolute path check
//split malloc fail

int	main(int ac, char **av, char **envp)
{
	int			pipe_fd[2];
	t_pipe_side	left, right;

	if (ac != 5)
		exit_error(1, NULL, NULL, AC2);
	init_all(&left, &right, pipe_fd);
	init_left_side(&left, av, envp);
	init_right_side(&right, &left, av, envp);
	if (left.is_valid)
	{
		if (pipe(pipe_fd) == -1)
			pipe_fail(&left, &right);
		left.pid = fork();
		if (left.pid == -1)
			fork_fail(&left, &right, pipe_fd);
		if (left.pid == 0)
			child_process1(&left, &right, pipe_fd, envp);
		right.pid = fork();
		if (right.pid == -1)
			fork_fail(&left, &right, pipe_fd);
		if (right.pid == 0)
			child_process2(&left, &right, pipe_fd, envp);
	}
	parent_process(&left, &right, pipe_fd);
	return (0);
}
