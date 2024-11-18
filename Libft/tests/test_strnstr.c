#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_in_middle()
{
	char arr1[] = "qwerty";
	char arr2[] = "wer";
	printf("test_in_middle\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_in_end()
{
	char arr1[] = "qwerty";
	char arr2[] = "ty";
	printf("test_in_end\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_in_start()
{
	char arr1[] = "qwerty";
	char arr2[] = "qwer";
	printf("test_in_start\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_size_too_short()
{
	char arr1[] = "qwerty";
	char arr2[] = "ty";
	printf("test_size_too_short\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, 4));
}

void test_partial_match()
{
	char arr1[] = "123123456";
	char arr2[] = "1234";
	printf("test_partial_match\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_partial_match_at_end()
{
	char arr1[] = "123123456";
	char arr2[] = "4567";
	printf("test_partial_match_at_end\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_no_match()
{
	char arr1[] = "123123456";
	char arr2[] = "546";
	printf("test_no_match\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_empty_little()
{
	char arr1[] = "123123456";
	char arr2[] = {0};
	printf("test_empty_little\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, sizeof(arr1)));
}

void test_warmashine()
{
	char arr1[] = "l ipsum";
	char arr2[] = "ipsum";
	printf("test_warmashine\n");
	printf("%s\n%s\n", arr1, arr2);
	printf("ft_strnstr result: %s\n", ft_strnstr(arr1, arr2, 6));
}

int main()
{
	test_in_middle();
	printf("\n\n");
	fflush(stdout);

	test_in_end();
	printf("\n\n");
	fflush(stdout);

	test_in_start();
	printf("\n\n");
	fflush(stdout);

	test_size_too_short();
	printf("\n\n");
	fflush(stdout);

	test_partial_match();
	printf("\n\n");
	fflush(stdout);

	test_partial_match_at_end();
	printf("\n\n");
	fflush(stdout);

	test_no_match();
	printf("\n\n");
	fflush(stdout);

	test_empty_little();
	printf("\n\n");
	fflush(stdout);

	test_warmashine();
	printf("\n\n");
	fflush(stdout);

	return 0;
}
