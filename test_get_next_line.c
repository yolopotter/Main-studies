#include <unistd.h> //read
#include <stdlib.h> //malloc
#include <stdio.h> //printf
#include <fcntl.h> //open

#define BUFFER_SIZE 1024

void	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	int i;

	dest_len = strlen(dest); //tee tää käsin tässä funktiossa
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup_len(const char *s, int len)
{
	char *dst;
	int i;

	if (!s)
		return (NULL);
	dst = (char *)malloc(1 + len * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *get_next_line(int fd)
{
	int bytes_read;
	char c;
	char *buffer;
	char *line;
	static char *str_s;
	int i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (str_s)
	{
		i = 0;
		while (str_s[i])
		{
			if (str_s[i] == '\n')
			{
				line = ft_strdup_len(str_s, i);
				str_s += i;
				return (line);
			}
		}
		line = ft_strdup_len(str_s, i);
		str_s = NULL;
	}

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			ft_strlcat(line, buffer, i); // tää funktio just tehty kaikki tästä alemmas kattomatta.
											// joutuu vielä muokkaa: käytä ehkä strjoinia i asti
			str_s = i + 1;
			free(buffer);
			return (line);
		}
		i++;
	}

	if (line == NULL)
		line = ft_strdup_len(buffer, i);
	else
	{
		char *temp;
		temp = line;
		line = malloc ()
	}

	if (i == 0 && bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return NULL;
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
