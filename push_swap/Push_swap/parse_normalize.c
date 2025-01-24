/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:27:39 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 11:19:07 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_calloc_minus_one(size_t nmemb, size_t size)
{
	int		*ptr;
	size_t	result;
	size_t	i;

	result = nmemb * size;
	if (nmemb && size != result / nmemb)
		return (NULL);
	ptr = malloc(result);
	if (ptr != NULL)
	{
		i = 0;
		while (i < nmemb)
		{
			ptr[i] = -1;
			i++;
		}
	}
	return (ptr);
}

static int	find_lowest_pos(int *dst, int *src, int len)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (dst[i] != -1)
		i++;
	nb = src[i];
	j = i;
	while (i < len - 1)
	{
		if (nb >= src[i] && dst[i] == -1)
		{
			nb = src[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	*normalize_sequence(int *src, int len)
{
	int	i;
	int	pos;
	int	*dst;

	dst = ft_calloc_minus_one(len, sizeof(int));
	if (!dst)
		exit_function(dst, 0);
	i = 0;
	while (i < len)
	{
		pos = find_lowest_pos(dst, src, len);
		dst[pos] = i;
		i++;
	}
	dst[i - 1] = -1;
	free (src);
	src = NULL;
	return (dst);
}
