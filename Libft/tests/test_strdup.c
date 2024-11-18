
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *create_big_string(int size)
{
	char *arr;

	arr = (char *)malloc(1 + size * sizeof(char));
	if (!arr)
	{
		printf("Memory allocation failed at creating big string\n");
		return (NULL);
	}
	int i = 0;
	while (i < size)
	{
		arr[i] = 'v';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void test_basic()
{
	char arr1[] = "qwerty";
	printf("test_basic\n");

	char *dst1 = ft_strdup(arr1);
	char *dst2 = strdup(arr1);
	printf("ft_strdup result: %s\n", dst1);
	printf("strdup result: %s", dst2);
	free(dst1);
	free(dst2);
}

void test_NULL()
{
	char *arr1 = NULL;
	printf("test_NULL\n");

	// char *dst1 = ft_strdup(arr1);
	char *dst2 = strdup(arr1);
	// printf("ft_strdup result: %s\n", dst1);
	printf("strdup result: %s", dst2);
	// free(dst1);
	free(dst2);
}

void test_big()
{
	char *arr1 = create_big_string(10000001);
	printf("test_big\n");

	char *dst1 = ft_strdup(arr1);
	char *dst2 = strdup(arr1);
	printf("ft_strdup result: %c\n", dst1[10000000]);
	printf("strdup result: %c", dst2[10000000]);
	free(dst1);
	free(dst2);
}

int main()
{
	// test_basic();
	// printf("\n\n");

	test_NULL();
	printf("\n\n");

	test_big();
	printf("\n\n");

	return 0;
}

