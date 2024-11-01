#include <stdio.h>
//#include <libft.h>

void test_exists_3occurences()
{
	char arr[] = "qrertry";
	char c = 'r';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_exists_1occurences()
{
	char arr[] = "qre6tr?";
	char c = '6';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_not_exists()
{
	char arr[] = "qwerty";
	char c = 'a';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_c_nullchar()
{
	char arr[] = "qwerty";
	char c = '\0';
	printf("ft_strrchr result: %s\n", ft_strrchr(arr, c));
	printf("strrchr result: %s", strrchr(arr, c));
}

void test_NULL()
{
	char *arr;
	char c = 'r';
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

	test_NULL();
	printf("\n\n");

	return 0;
}
