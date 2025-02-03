#include <stdio.h>
#include "../inc/pipex.h"

char	**parse_cmd(char *av)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	return (cmd);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;
	char	*exec;

	i = 0;
	while (*envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			break ;
		i++;
	}
	paths = ft_split(envp[i] + 5, ':');

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(paths[i], cmd);
		if (access(exec, F_OK | X_OK) == 0)
		{
			// free_paths(paths);
			return (exec);
		}
		free(exec);
		exec = NULL;
		i++;
	}
	return (paths[i]);
}
int	main(int ac, char **av, char **envp)
{
	char **cmd1 = parse_cmd(av[2]);
	char **cmd2 = parse_cmd(av[3]);
	char *path1 = find_path(cmd1[0], envp);
	char *path2 = find_path(cmd2[0], envp);

	int pipe1[2];
	if (pipe(pipe1) == -1)
	{
		perror("pipe");
		return 1;
	}

	pid_t pid1 = fork();
	if (pid1 == -1) {
		perror("fork");
		return 1;
	}

	if (pid1 == 0)
	{
		// Child process: Executes `ls -l`
		int fd = open(av[1], O_RDONLY);

		close(pipe1[0]);
		dup2(fd, STDIN_FILENO);
		dup2(pipe1[1], STDOUT_FILENO);
		close(fd);
		close(pipe1[1]);

		// char *cmd = "/usr/bin/wc";
		// char *args[] = {"wc", "-l", NULL};
		execve(path1, cmd1, NULL);
		perror("execve");
		exit (1);
	}

	pid_t pid2 = fork();
	if (pid2 == -1) {
		perror("fork");
		return 1;
	}
	if (pid2 == 0)
	{
		// Child process: Executes `wc -l`

		close(pipe1[1]);
		dup2(pipe1[0], STDIN_FILENO);
		close(pipe1[0]);

		execve(path2, cmd2, NULL);
		perror("execve");
		exit (1);
	}

	close(pipe1[0]);
	close(pipe1[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
