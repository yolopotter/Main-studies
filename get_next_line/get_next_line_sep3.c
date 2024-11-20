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
#include <stdlib.h> //malloc, size_t
#include <string.h> //strdup
#include <stdio.h> //printf
#include <fcntl.h> //open

#define BUFFER_SIZE 34

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
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

void	fill_str(char *dst, const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((1 + len) * sizeof(char));
	if (!dst)
		return (NULL);
	fill_str(dst, s1, s2);
	return (dst);
}

char	*fill_line(int fd, char *str_s, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (!str_s)
			str_s = ft_strdup("");
		if (ft_strchr(str_s, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		str_s = ft_strjoin(str_s, buffer);
	}
	return (str_s);
}

char	*set_reminder(char **line)
{
	char	*str_s;
	int		i;

	i = 0;
	while((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\n')
	{
		str_s = strdup(&(*line)[i + 1]);
		(*line)[i + 1] = '\0';
		return (str_s);
	}
	str_s = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str_s;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0 ,0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = fill_line(fd, str_s, buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	str_s = set_reminder(&line);
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
