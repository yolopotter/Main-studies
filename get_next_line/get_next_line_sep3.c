/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_sep3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:36:38 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/19 15:42:05 by vlopatin         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	int		i;

	len = ft_strlen(s) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*fill_line(int fd, char **str_s, char *buffer)
{
	ssize_t bytes_read;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!str_s)
		str_s = ft_strdup("");
		// str_s = strjoin( vanha, bufferi)
		// if (strchr(str_s, '\n'))
			//break ;
		//return str_s;
	}
	//return str_s;
}

char	*set_reminder(char *line)
{
	char *str_s;
	//str_s = strnstr(line, '\n')
}

char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *str_s;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	line = fill_line(fd, &str_s, buffer);

	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	str_s = set_reminder(line);
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
