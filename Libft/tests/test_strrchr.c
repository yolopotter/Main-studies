#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_exists_3occurences()
{
	printf("test_exists_3occurences\n");
	char arr[] = "qrertry";
	char c = 'r';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_exists_1occurences()
{
	printf("test_exists_1occurences\n");
	char arr[] = "qre6tr?";
	char c = '6';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_not_exists()
{
	printf("test_not_exists\n");
	char arr[] = "qwerty";
	char c = 'a';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_c_nullchar()
{
	printf("test_c_nullchar\n");
	char arr[] = "qwerty";
	char c = '\0';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

int main()
{
	test_exists_3occurences();
	printf("\n\n");

	test_exists_1occurences();
	printf("\n\n");

	test_not_exists();
	printf("\n\n");

	test_c_nullchar();
	printf("\n\n");

	return 0;
}
