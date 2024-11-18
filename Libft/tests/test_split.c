#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	free_result(char **result)
{
	int i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	test_basic()
{
	char *s = "Hello world this is";
	char **result = ft_split(s, ' ');
	printf("Basic split:\n");
	printf("Expexted: Hello, world, this, is, (nil)\n");
	printf("Result: %s, %s, %s, %s, %p\n\n", result[0], result[1], result[2], result[3], result[4]);
	free_result(result);
}

void	test_2()
{
	char *s = "   Hello    world    this is   ";
	char **result = ft_split(s, ' ');
	printf("More delimiters everywhere:\n");
	printf("Expexted: Hello, world, this, is, (nil)\n");
	printf("Result: %s, %s, %s, %s, %p\n\n", result[0], result[1], result[2], result[3], result[4]);
	free_result(result);
}

void	test_empty_s()
{
	char *s = "";
	char **result = ft_split(s, ' ');
	printf("Empty string:\n");
	printf("Expexted: (nil)\n");
	printf("Result: %p\n\n", result[0]);
	free_result(result);
}

void	test_no_delimiters()
{
	char *s = "   Hello    world    this is   ";
	char **result = ft_split(s, '2');
	printf("No delimiters:\n");
	printf("Expexted:    Hello    world    this is   , (nil)\n");
	printf("Result: %s, %p\n\n", result[0], result[1]);
	free_result(result);
}

void	test_delimiters_only()
{
	char *s = "222222";
	char **result = ft_split(s, '2');
	printf("Delimiters only:\n");
	printf("Expexted:(nil)\n");
	printf("Result: %p\n\n", result[0]);
	free_result(result);
}

void	test_NULL()
{
	char *s = NULL;
	char **result = ft_split(s, '2');
	printf("s is NULL:\n");
	printf("Expexted:(nil)\n");
	printf("Result: %p\n\n", result);
}

int main()
{
	test_basic();
	test_2();
	test_empty_s();
	test_no_delimiters();
	test_delimiters_only();
	test_NULL();
	return 0;
}
