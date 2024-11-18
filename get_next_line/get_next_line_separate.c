/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_separate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:38 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/18 16:20:38 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read
#include <stdlib.h> //malloc
#include <string.h> //strdup
#include <stdio.h> //printf
#include <fcntl.h> //open

#define BUFFER_SIZE 2

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strndup(const char *s, int len)
{
	char	*dst;
	int		i;

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

char	*create_line(char *buffer, char *line, int i)
{
	if (line == NULL)
		line = ft_strndup(buffer, i + 1);
	else
	{
		char *temp;
		temp = line;
		line = malloc (ft_strlen(line) + i + 1);
		if (!line)
		{
			free (buffer);
			return (NULL);
		}
		strcpy(line, temp);
		strncat(line, buffer, i + 1);
		free(temp);
	}
	free(buffer);
	return (line);
}

char *get_next_line(int fd)
{
	int bytes_read;
	char *buffer;
	char *line;
	static char *str_s;
	int i;

	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	if (str_s)
	{
		while (str_s[i] && str_s[i] != '\n')
			i++;
		line = ft_strndup(str_s, i + 1);
		if (str_s[i] != '\0')
		{
			str_s = ft_strndup(&str_s[i + 1], BUFFER_SIZE);
			return (line);
		}
		else
		{
			free(str_s);
			str_s = NULL;
		}
	}
	i = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				str_s = ft_strndup(&buffer[i + 1], BUFFER_SIZE);
				return (create_line(buffer, line, i));
			}
			i++;
		}
		str_s = ft_strndup(&buffer[i + 1], BUFFER_SIZE);
		line = create_line(buffer, line, i);
	}
	free (buffer);
	return (NULL);
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
		printf("fd: %i, content: %s\n", fd, str);
		free(str);
		i++;
	}
	return 0;
}
