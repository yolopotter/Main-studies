/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/07 15:09:54 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(int *fd, int *pipe_fd, char **cmd1, char **envp, char *path1)
{
	close(pipe_fd[0]);
	pipe_fd[0] = -1;
	close(fd[1]);
	fd[1] = -1;
	dup2(fd[0], STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	if (execve(path1, cmd1, envp) == -1)
	{
		close_fds(fd, pipe_fd, 2);
		exit_error(6, cmd1, path1, EXECVE);
	}
}

void	child_process2(int *fd, int *pipe_fd, char **cmd2, char **envp, char *path2)
{
	close(pipe_fd[1]);
	pipe_fd[1] = -1;
	close(fd[0]);
	fd[0] = -1;
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(path2, cmd2, envp) == -1)
	{
		close_fds(fd, pipe_fd, 2);
		exit_error(6, cmd2, path2, EXECVE);
	}
}

void	parent_process(int *fd, int *pipe_fd, int pid1, int pid2)
{
	int	status1;
	int	status2;

	close_fds(fd, pipe_fd, 2);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
}

// move cmd retriaval to parent process
// check fd closures at different fails
// split malloc fails

int	init_left_side()
{
	
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];
	int		fd[2];
	// int		exit_status;
	char	**cmd1, **cmd2;
	char	*path1, *path2;
	t_pipe_side	left, right;

	if (ac != 5)
		exit_error(1, NULL, NULL, AC2);

	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		exit_error(14, NULL, av[1], OPEN);
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] == -1)
	{
		close_fds(fd, NULL, 2);
		exit_error(4, NULL, av[5], OPEN);
	}
	cmd1 = ft_split(av[2], ' ');
	if (!cmd1[0])
	{
		close_fds(fd, NULL, 2);
		ft_free_split(cmd1);
		cmd1 = NULL;
		exit_error(15, NULL, NULL, NULL);
	}
	// path1 = NULL;
	if (cmd1)
		path1 = find_path(cmd1, envp, NON_FATAL);
	cmd2 = ft_split(av[3], ' ');
	if (!cmd2[0])
	{
		close_fds(fd, NULL, 2);
		if (path1)
			ft_free_split(cmd1);
		cmd1 = NULL;
		ft_free_split(cmd2);
		cmd2 = NULL;
		exit_error(5, NULL, NULL, NULL);
	}
	path2 = find_path(cmd2, envp, FATAL);
	pid1 = -1;
	pid2 = -1;
	if (fd[0] != -1 && path1 != NULL)
	{
		if (pipe(pipe_fd) == -1)
			pipe_fail(fd, cmd1, cmd2);
		pid1 = fork();
		if (pid1 == -1)
			fork_fail(fd, pipe_fd, cmd1, cmd2);
		if (pid1 == 0)
			child_process1(fd, pipe_fd, cmd1, envp, path1);
		pid2 = fork();
		if (pid2 == -1)
			fork_fail(fd, pipe_fd, cmd1, cmd2);
		if (pid2 == 0)
			child_process2(fd, pipe_fd, cmd2, envp, path2);
	}
	parent_process(fd, pipe_fd, pid1, pid2);
	return (0);
}
