/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_toimiva2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:38 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/19 15:33:01 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read
#include <stdlib.h> //malloc
#include <string.h> //strdup
#include <stdio.h> //printf
#include <fcntl.h> //open

#define BUFFER_SIZE 6

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

void	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	dest_len = 0;
	while (dest[dest_len])
		dest_len++;
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
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

char	*create_line(char *line, char *buffer, int i)
{
	char	*dst;

	if (line == NULL)
	{
		line = ft_strndup(buffer, i + 1);
		return (line);
	}
	dst = (char *)malloc(ft_strlen(line) + i + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, line, ft_strlen(line) + 1);
	ft_strlcat(dst, buffer, ft_strlen(line) + i + 1);
	return (dst);
}

char	*fill_line(int fd, char **str_s, char *buffer)
{
	char *line;
	int i;
	ssize_t bytes_read;

	line = NULL;
	i = 0;
	if (*str_s)
	{
		while ((*str_s)[i] && (*str_s)[i] != '\n')
			i++;
		line = ft_strndup(*str_s, i + 1);
		if ((*str_s)[i] != '\0')
		{
			char *temp = ft_strndup(&(*str_s)[i + 1], BUFFER_SIZE);
			free(*str_s);
			*str_s = temp;
			return (line);
		}
		else
		{
			free(*str_s);
			*str_s = NULL;
		}
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buffer[bytes_read] = '\0';
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				*str_s = ft_strndup(&buffer[i + 1], BUFFER_SIZE);
				return (create_line(line, buffer, i + 1));
			}
			i++;
		}
		line = create_line(line, buffer, i);
	}
	return(NULL);
}

char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *str_s;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(str_s);
		free(buffer);
		str_s = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);

	line = fill_line(fd, &str_s, buffer);

	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	return (line);
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
