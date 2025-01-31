/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:28:35 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/31 12:16:43 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //NULL
#include <unistd.h> //execve, fork
#include <fcntl.h> //pid_t
#include <stdio.h>
#include <sys/wait.h> //wait

int	main(int ac, char **av)
{
    // if (ac != 2) {
    //     fprintf(stderr, "Usage: %s <file>\n", av[0]);
    //     return 1;
    // }
    av[1] = "file1";
    int fd = open(av[1], O_RDONLY);

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }
	printf("first time: pipe fd[0]: %i\n", pipe_fd[0]);
	printf("first time: pipe fd[1]: %i\n", pipe_fd[1]);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
	printf("pid %i\n", pid);

	if (pid == 0)
	{
        // Child process: Executes `wc -l`
		printf("pipe fd[1] %i\n", pipe_fd[1]);
		printf("pipe fd[0] %i\n", pipe_fd[0]);
        close(pipe_fd[1]);
        dup2(pipe_fd[0], STDIN_FILENO); // Replace stdin with pipe
        close(pipe_fd[0]);

        char *cmd = "/usr/bin/wc";
        char *args[] = {"wc", "-l", NULL};
        execve(cmd, args, NULL);
        perror("execve");
        return 1;
	}
	else
	{
        // Parent process: Reads file and sends content through pipe
        close(pipe_fd[0]);

        char buffer[1024];
        ssize_t bytes_read;
        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
            write(pipe_fd[1], buffer, bytes_read);
        }

        close(fd);
        close(pipe_fd[1]);
        wait(NULL); // Wait for child process to finish
	}
	// printf("pid %i\n", pid);
	return (0);
}

if (pid == 0)
{
    // Child process
    printf("pipe fd[1] %i\n", pipe_fd[1]);
    printf("pipe fd[0] %i\n", pipe_fd[0]);
    close(pipe_fd[1]); // Close write end as we're only reading

    char buffer[1024];
    ssize_t bytes_read;

    // Read from pipe and write to stdout
    while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // Close the read end of the pipe
    close(pipe_fd[0]);

    // Exit the child process
    exit(0);
}

