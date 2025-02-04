/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:10 by vlopatin          #+#    #+#             */
/*   Updated: 2025/02/04 12:08:04 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process1(int *pipe_fd, char **av, char **envp)
{
	char **cmd1 = parse_cmd(av[2]);
	char *path1 = find_path(cmd1, envp);
	int fd1 = -1; //open(av[1], O_RDONLY);
	if (fd1 == -1)
		exit_error(3, cmd1, path1, OPEN);
	close(pipe_fd[0]);
	dup2(fd1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd1);
	close(pipe_fd[1]);
	execve(path1, cmd1, envp);
	exit_error(3, cmd1, path1, EXECVE);
}

void	child_process2(int *pipe_fd, char **av, char **envp)
{
	char **cmd2 = parse_cmd(av[3]);
	char *path2 = find_path(cmd2, envp);
	int fd2 = open(av[4], O_WRONLY);
	if (fd2 == -1)
		exit_error(3, cmd2, path2, OPEN);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(pipe_fd[0]);
	execve(path2, cmd2, envp);
	exit_error(3, cmd2, path2, EXECVE);
}

void	parent_process(int *pipe_fd, int pid1, int pid2)
{
	// int	status1;
	// int	status2;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);  // Wait for first child
	waitpid(pid2, NULL, 0);  // Wait for second child
	// waitpid(pid1, &status1, 0);  // Wait for first child
	// waitpid(pid2, &status2, 0);  // Wait for second child
	// if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
	//     return WEXITSTATUS(status1);
	// if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
	//     return WEXITSTATUS(status2);

	// return (0);
}

int main(int ac, char **av, char **envp)
{
	pid_t pid1;
	pid_t pid2;
	if (ac != 5)
		exit_error(1, NULL, NULL, AC);
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1)
		exit_error(2, NULL, NULL, PIPE);
	pid1 = fork();
	if (pid1 == -1)
		exit_error(2, NULL, NULL, FORK);
	if (pid1 == 0)
		child_process1(pipe_fd, av, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_error(2, NULL, NULL, FORK);
	if (pid2 == 0)
		child_process2(pipe_fd, av, envp);
	parent_process(pipe_fd, pid1, pid2);
	return (0);
}
