#include <stdio.h>
#include <libft.h>

void test_exists()
{
	char arr[] = "qwerty";
	char c = 'r';
	printf("ft_strchr result: %s\n", ft_strchr(arr, c));
	printf("strchr result: %s", strchr(arr, c));
}

void test_not_exists()
{
	char arr[] = "qwerty";
	char c = 'a';
	printf("ft_strchr result: %s\n", ft_strchr(arr, c));
	printf("strchr result: %s", strchr(arr, c));
}

void test_c_nullchar()
{
	char arr[] = "qwerty";
	char c = '\0';
	printf("ft_strchr result: %s\n", ft_strchr(arr, c));
	printf("strchr result: %s", strchr(arr, c));
}

void test_NULL()
{
	char *arr;
	char c = 'r';
	printf("ft_strchr result: %s\n", ft_strchr(arr, c));
	printf("strchr result: %s", strchr(arr, c));
}

int main()
{
	test_exists();
	printf("\n\n");

	test_not_exists();
	printf("\n\n");

	test_c_nullchar();
	printf("\n\n");

	test_NULL();
	printf("\n\n");

	return 0;
}
