#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_exists()
{
	char arr[] = "qwerty";
	char c = 'r';
	printf("ft_memchr result: %s\n", (char *)ft_memchr(arr, c, sizeof(arr)));
	printf("memchr result: %s", (char *)memchr(arr, c, sizeof(arr)));
}

void test_not_exists()
{
	char arr[] = "qwerty";
	char c = 'a';
	printf("ft_memchr result: %s\n", (char *)ft_memchr(arr, c, sizeof(arr)));
	printf("memchr result: %s", (char *)memchr(arr, c, sizeof(arr)));
}

void test_not_in_range()
{
	char arr[] = "qwerty";
	char c = 'r';
	printf("ft_memchr result: %s\n", (char *)ft_memchr(arr, c, 3));
	printf("memchr result: %s", (char *)memchr(arr, c, 3));
}

void test_exactly_in_range()
{
	char arr[] = "qwerty";
	char c = 'r';
	printf("ft_memchr result: %s\n", (char *)ft_memchr(arr, c, 4));
	printf("memchr result: %s", (char *)memchr(arr, c, 4));
}

void test_c_nullchar()
{
	char arr[] = "qwerty";
	char c = '\0';
	printf("ft_memchr result: %s\n", (char *)ft_memchr(arr, c, sizeof(arr)));
	printf("memchr result: %s", (char *)memchr(arr, c, sizeof(arr)));
}

void test_NULL()
{
	char *arr;
	char c = 'r';
	printf("ft_memchr result: %s\n", (char *)ft_memchr(arr, c, sizeof(arr)));
	printf("memchr result: %s", (char *)memchr(arr, c, sizeof(arr)));
}

int main()
{
	test_exists();
	printf("\n\n");

	test_not_exists();
	printf("\n\n");

	test_not_in_range();
	printf("\n\n");

	test_exactly_in_range();
	printf("\n\n");

	test_c_nullchar();
	printf("\n\n");

	test_NULL();
	printf("\n\n");

	return 0;
}
