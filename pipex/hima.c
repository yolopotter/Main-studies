#include <stdlib.h> //NULL
#include <unistd.h> //execve, fork
#include <fcntl.h> //pid_t
#include <stdio.h>
#include <sys/wait.h> //wait

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_ARGS 64
#define MAX_PATH_LEN 1024
#define AC "Usage: ./pipex file1 cmd1 cmd2 file2"
#define FORK "Fork"
#define PIPE "Pipe"
#define OPEN "Open"
#define EXECVE "Execve"


void	exit_error(int error, const char *msg)
{
	// if (error == 1)
	// 	ft_putendl_fd((char *)msg, 2);
	if (error == 2)
		perror((char *)msg);
	exit(1);
}

char **parse_cmd(char *cmd_str) {
    char **args = malloc(MAX_CMD_ARGS * sizeof(char *));
    if (!args)
		return NULL;

    int i = 0;
    char *token = strtok(cmd_str, " ");
    while (token != NULL && i < MAX_CMD_ARGS - 1) {
        args[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

char *find_path(char *cmd, char **envp) {
    char *path_env = NULL;
    for (int i = 0; envp[i]; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_env = envp[i] + 5;
            break;
        }
    }
    if (!path_env)
		return NULL;

    char *path = strdup(path_env);
    char *dir = strtok(path, ":");
    static char full_path[MAX_PATH_LEN];

    while (dir != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
		{
            free(path);
            return strdup(full_path);
        }
        dir = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}

void	child_process1(int *pipe_fd, char **av, char **envp)
{
	char **cmd1 = parse_cmd(av[2]);
	char *path1 = find_path(cmd1[0], envp);
	int fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		exit_error(2, OPEN);

	close(pipe_fd[0]);
	dup2(fd1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd1);
	close(pipe_fd[1]);

	execve(path1, cmd1, envp);
	exit_error(2, EXECVE);
	exit(127);
}

void	child_process2(int *pipe_fd, char **av, char **envp)
{
	char **cmd2 = parse_cmd(av[3]);
	char *path2 = find_path(cmd2[0], envp);
	int fd2 = open(av[4], O_WRONLY);
	if (fd2 == -1)
		exit_error(2, OPEN);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(pipe_fd[0]);

	execve(path2, cmd2, envp);
	exit_error(2, EXECVE);
	exit(127);
}

void	parent_process(int *pipe_fd, int pid1, int pid2)
{
	// Parent process: Closes all pipe ends and waits for children
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    waitpid(pid1, NULL, 0);  // Wait for first child
    waitpid(pid2, NULL, 0);  // Wait for second child
}

int main(int ac, char **av, char **envp)
{
	pid_t pid1;
	pid_t pid2;
	// if (ac != 5)
	// 	exit_error(1, AC);
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1)
		exit_error(2, PIPE);
	pid1 = fork();
	if (pid1 == -1)
		exit_error(2, FORK);
	if (pid1 == 0)
		child_process1(pipe_fd, av, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_error(2, FORK);
	if (pid2 == 0)
		child_process2(pipe_fd, av, envp);
	parent_process(pipe_fd, pid1, pid2);
	return (0);
}
