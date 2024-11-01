/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:03:59 by marvin            #+#    #+#             */
/*   Updated: 2024/11/01 16:03:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void *memset(void *s, int c, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if(nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		memset(ptr, 0, nmemb * size);
	return (ptr);
}

void	test_int_short()
{
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	int i = 0;
	printf("Test normal int\nMemory content:\n");
	while (i < 5)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n\n");
	free(arr);
}

void	test_zero_size()
{
	int *arr = (int *)ft_calloc(0, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	int i = 0;
	printf("Test zero size\nMemory content:\n");
	while (i < 5)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n\n");
	free(arr);
}

void	test_4size()
{
	int a = 1;
	int b = 4;
	char c = 'h';
	char *arr = ft_calloc(a, b);

	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	printf("Test string\nMemory content:\n");
	printf("Before: %.*s\n", a * b, arr);
	memset(arr, c, (a * b));
	printf("After: %.*s\n", a * b, arr);
	printf("\n\n");
	free(arr);
}

int main()
{
	test_int_short();
	test_4size();
	return 0;
}
