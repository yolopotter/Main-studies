
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void	test_int_short()
{
	printf("Test normal short int ft_calloc\nMemory content:\n");
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	int i = 0;
	while (i < 5)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n\n");
	free(arr);
}

void	test_int_short_o()
{
	printf("Test normal short int calloc\nMemory content:\n");
	int *arr = (int *)calloc(5, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	int i = 0;
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
	printf("Test zero size ft_calloc\nMemory content:\n");
	int *arr = (int *)ft_calloc(0, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	int i = 0;
	while (i < 5)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n\n");
	free(arr);
}

void	test_zero_size_o()
{
	printf("Test zero size calloc\nMemory content:\n");
	int *arr = (int *)calloc(0, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	int i = 0;
	while (i < 5)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n\n");
	free(arr);
}

void	test_big_size()
{
	printf("Test big size ft_calloc\nMemory content:\n");
	int *arr = (int *)ft_calloc(1000000, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	else
	{
		printf("Large Memory allocation succeeded\n\n");
		free(arr);
	}
}

void	test_big_size_o()
{
	printf("Test big size calloc\nMemory content:\n");
	int *arr = (int *)calloc(1000000, sizeof(int));
	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	else
	{
		printf("Large Memory allocation succeeded\n\n");
		free(arr);
	}
}

void	test_4size()
{
	printf("Test string ft_calloc\nMemory content:\n");
	int a = 1;
	int b = 4;
	char c = 'h';
	char *arr = ft_calloc(a, b);

	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	printf("Before: %.*s\n", a * b, arr);
	memset(arr, c, (a * b));
	printf("After: %.*s\n", a * b, arr);
	printf("\n");
	free(arr);
}

void	test_4size_o()
{
	printf("Test string calloc\nMemory content:\n");
	int a = 1;
	int b = 4;
	char c = 'h';
	char *arr = calloc(a, b);

	if (arr == NULL)
	{
		printf("Memory allocation failed\n\n");
		return;
	}
	printf("Before: %.*s\n", a * b, arr);
	memset(arr, c, (a * b));
	printf("After: %.*s\n", a * b, arr);
	printf("\n\n");
	free(arr);
}

int main()
{
	test_int_short();
	test_int_short_o();
	test_zero_size();
	test_zero_size_o();
	test_big_size();
	test_big_size_o();
	test_4size();
	test_4size_o();
	return 0;
}
