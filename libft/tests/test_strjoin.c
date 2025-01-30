#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	test_normal()
{
	char *arr1 = "123";
	char *arr2 = "abcd";
	printf("\nexpected result: 123abcd\n");
	printf("ft_strjoin result: %s\n\n", ft_strjoin(arr1, arr2));
}

void	test_arr1_empty()
{
	char *arr1 = "";
	char *arr2 = "abcd";
	printf("expected result: abcd\n");
	printf("ft_strjoin result: %s\n\n", ft_strjoin(arr1, arr2));
}

void	test_arr2_empty()
{
	char *arr1 = "1234";
	char *arr2 = "";
	printf("expected result: 1234\n");
	printf("ft_strjoin result: %s\n\n", ft_strjoin(arr1, arr2));
}

void	test_both_empty()
{
	char *arr1 = "";
	char *arr2 = "";
	printf("expected result: \n");
	printf("ft_strjoin result: %s\n\n", ft_strjoin(arr1, arr2));
}

void	test_NULL()
{
	char *arr1 = "1234";
	char *arr2 = NULL;

	printf("expected result: NULL\n");
	char *result = ft_strjoin(arr1, arr2);
	if (result)
		printf("ft_strjoin result: %s\n\n", result);
	else
		printf("ft_strjoin result: NULL\n\n");
}

void	test_war1()
{
	char	arr1[] = "lorem ipsum";
	char	arr2[] = "\0";
	printf("expected result: lorem ipsum\n");
	printf("ft_strjoin result: %s\n\n", ft_strjoin(arr1, arr2));
}

int main()
{
	test_normal();
	test_arr1_empty();
	test_arr2_empty();
	test_both_empty();
	test_NULL();
	test_war1();
	return 0;
}
