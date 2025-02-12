/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/12 11:19:30 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(t_side *left, t_side *right, int *pipe_fd, char **envp)
{
	left->pid = fork();
	if (left->pid == -1)
		fork_fail(left, right, pipe_fd);
	if (left->pid == 0)
	{
		close_fds(pipe_fd[0], NULL, NULL, 0);
		close_fds(right->fd, NULL, NULL, 0);
		// dup2(left->fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close_fds(left->fd, NULL, NULL, 0);
		close_fds(pipe_fd[1], NULL, NULL, 0);
		execve(left->path, left->cmd, envp);
			// exit_error(6, &(left->cmd), &(left->path), EXECVE);
	}
}

void	child_process2(t_side *left, t_side *right, int *pipe_fd, char **envp)
{
	right->pid = fork();
	if (right->pid == -1)
		fork_fail(left, right, pipe_fd);
	if (right->pid == 0)
	{
		close_fds(pipe_fd[1], NULL, NULL, 0);
		close_fds(left->fd, NULL, NULL, 0);
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(right->fd, STDOUT_FILENO);
		close_fds(pipe_fd[0], NULL, NULL, 0);
		close_fds(right->fd, NULL, NULL, 0);
		execve(right->path, right->cmd, envp);
			// exit_error(6, &(right->cmd), &(right->path), EXECVE);
	}
}

void	parent_process(t_side *left, t_side *right, int *pipe_fd)
{
	int	status;

	close_fds(-1, pipe_fd, NULL, 2);
	close_free_left(left);
	close_free_right(right);
	waitpid(right->pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
}

//to fix: make child1 run even if path is not found OR file open fails. Only dont run execve when "".
//Any other input into execve should be fine. perror will print correct error after fail inside execve

//Issue currently:
// % ./pipex file5 "cat" "sad" file9
//pipex: Command not found: sad


int	main(int ac, char **av, char **envp)
{
	int		pipe_fd[2];
	t_side	left;
	t_side	right;

	if (ac != 5)
		exit_error(1, NULL, NULL, AC2);
	init_all(&left, &right, pipe_fd);
	init_left_side(&left, av, envp);
	if (pipe(pipe_fd) == -1)
		pipe_fail(&left, &right);
	// printf("left.is_valid %i\n", left.is_valid);
	if (left.is_valid)
	{
		child_process1(&left, &right, pipe_fd, envp);
		waitpid(left.pid, NULL, WNOHANG);
	}
	else
		dup2(left.fd, STDIN_FILENO);
	init_right_side(&left, &right, av, envp);
	child_process2(&left, &right, pipe_fd, envp);
	parent_process(&left, &right, pipe_fd);
	return (0);
}
