#include <unistd.h> //read
#include <stdlib.h> //malloc
#include <stdio.h> //printf
#include <fcntl.h> //open

#define BUFFER_SIZE 1024

char *get_next_line(int fd)
{
	int byte;
	char c;
	char *buffer;
	int i;

	byte = read(fd, &c, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	i = 0;
	while (byte != 0)
	{
		buffer[i] = c;
		i++;
		if (c == '\n' || c == -1)
			break ;
		byte = read(fd, &c, 1);
	}
	if (i == 0 && byte == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

int main()
{
	char *path;
	char *str;
	int i;
	int fd;

	path = "test.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 6)
	{
		str = get_next_line(fd);
		printf("i: %i\n", i);
		printf("fd: %i, content: %s\n\n", fd, str);
		i++;
	}
	return 0;
}
