/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/06 16:20:58 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(int *fd, int *pipe_fd, char **av, char **envp)
{
	char	**cmd1;
	char	*path1;

	close(pipe_fd[0]);
	pipe_fd[0] = -1;
	close(fd[1]);
	fd[1] = -1;
	cmd1 = ft_split(av[2], ' ');
	if (!cmd1[0])
	{
		close(pipe_fd[1]);
		close(fd[0]);
		exit_error(5, cmd1, NULL, NULL);
	}
	path1 = find_path(cmd1, envp);
	dup2(fd[0], STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	if (execve(path1, cmd1, envp) == -1)
	{
		close_fds(fd, pipe_fd, 2);
		exit_error(6, cmd1, path1, EXECVE);
	}
}

void	child_process2(int *fd, int *pipe_fd, char **av, char **envp)
{
	char	**cmd2;
	char	*path2;

	close(pipe_fd[1]);
	pipe_fd[1] = -1;
	close(fd[0]);
	fd[0] = -1;
	cmd2 = ft_split(av[3], ' ');
	if (!cmd2[0])
	{
		close(pipe_fd[0]);
		close(fd[1]);
		exit_error(5, cmd2, NULL, NULL);
	}
	path2 = find_path(cmd2, envp);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(path2, cmd2, envp) == -1)
	{
		close_fds(fd, pipe_fd, 2);
		exit_error(6, cmd2, path2, EXECVE);
	}
}

int	parent_process(int *fd, int *pipe_fd, int pid1, int pid2)
{
	int	status1;
	int	status2;

	close_fds(fd, pipe_fd, 2);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WEXITSTATUS(status2) == 42 || WEXITSTATUS(status1) == 42)
	{
		if (WEXITSTATUS(status1) == 42)
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putendl_fd(PATH1, 2);
		}
		if (WEXITSTATUS(status2) == 42)
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putendl_fd(PATH1, 2);
			return(127);
		}
	}
	return (WEXITSTATUS(status2));
}

// move cmd retriaval to parent process
// check fd closures at different fails
// split malloc fails

int	main(int ac, char **av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];
	int		fd[2];
	int		exit_status;

	if (ac != 5)
		exit_error(1, NULL, NULL, AC2);

	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		exit_error(14, NULL, av[1], OPEN);
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] == -1)
	{
		close_fds(fd, NULL, 2);
		exit_error(4, NULL, av[1], OPEN);
	}
	pid1 = -1;
	pid2 = -1;
	if (fd[0] != -1)
	{
		if (pipe(pipe_fd) == -1)
			pipe_fail(fd);
		pid1 = fork();
		if (pid1 == -1)
			fork_fail(fd, pipe_fd);
		if (pid1 == 0)
			child_process1(fd, pipe_fd, av, envp);
		pid2 = fork();
		if (pid2 == -1)
			fork_fail(fd, pipe_fd);
		if (pid2 == 0)
			child_process2(fd, pipe_fd, av, envp);
	}
	exit_status = parent_process(fd, pipe_fd, pid1, pid2);
	return (exit_status);
}
