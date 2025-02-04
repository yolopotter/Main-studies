/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/04 15:30:08 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(int *pipe_fd, char **av, char **envp)
{
	char	**cmd1;
	char	*path1;
	int		fd;

	close(pipe_fd[0]);
	cmd1 = ft_split(av[2], ' ');
	path1 = find_path(cmd1, envp);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(pipe_fd[1]);
		exit_error(3, cmd1, path1, OPEN);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	execve(path1, cmd1, envp);
	close(fd);
	close(pipe_fd[1]);
	exit_error(3, cmd1, path1, EXECVE);
}

void	child_process2(int *pipe_fd, char **av, char **envp)
{
	char	**cmd2;
	char	*path2;
	int		fd;

	close(pipe_fd[1]);
	cmd2 = ft_split(av[3], ' ');
	path2 = find_path(cmd2, envp);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		close(pipe_fd[0]);
		exit_error(3, cmd2, path2, OPEN);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	execve(path2, cmd2, envp);
	close(fd);
	close(pipe_fd[0]);
	exit_error(3, cmd2, path2, EXECVE);
}

void	parent_process(int *pipe_fd, int pid1, int pid2)
{
	// int	status1;
	// int	status2;

 	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0); // Wait for first child
	waitpid(pid2, NULL, 0);  // Wait for second child
	// waitpid(pid1, &status1, 0);  // Wait for first child
	// waitpid(pid2, &status2, 0);  // Wait for second child
	// if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
	//     return WEXITSTATUS(status1);
	// if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
	//     return WEXITSTATUS(status2);

	// return (0);
}

// check how wexitstatus works
//check fd closures at different fails

int	main(int ac, char **av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];

	if (ac != 5)
		exit_error(1, NULL, NULL, AC);
	if (pipe(pipe_fd) == -1)
		exit_error(2, NULL, NULL, PIPE);
	pid1 = fork();
	if (pid1 == -1)
		fork_fail(pipe_fd);
	if (pid1 == 0)
		child_process1(pipe_fd, av, envp);
	pid2 = fork();
	if (pid2 == -1)
		fork_fail(pipe_fd);
	if (pid2 == 0)
		child_process2(pipe_fd, av, envp);
	parent_process(pipe_fd, pid1, pid2);
	return (0);
}
