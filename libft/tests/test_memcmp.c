#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_same()
{
	char arr1[] = "qwerty";
	char arr2[] = "qwerty";
	printf("test_same\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, sizeof(arr1)));
	printf("memcmp result: %i", memcmp(arr1, arr2, sizeof(arr1)));
}

void test_bigger()
{
	char arr1[] = "qwzrty";
	char arr2[] = "qwerty";
	printf("test_bigger\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, sizeof(arr1)));
	printf("memcmp result: %i", memcmp(arr1, arr2, sizeof(arr1)));
}

void test_smaller()
{
	char arr1[] = "qw0rty";
	char arr2[] = "qwerty";
	printf("test_smaller\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, sizeof(arr1)));
	printf("memcmp result: %i", memcmp(arr1, arr2, sizeof(arr1)));
}

void test_length1()
{
	char arr1[] = "qwert0";
	char arr2[] = "qwerty";
	printf("test_length1\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, 0));
	printf("memcmp result: %i", memcmp(arr1, arr2, 0));
}

void test_length2()
{
	char arr1[] = "qwert0";
	char arr2[] = "qwerty";
	printf("test_length2\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, 5));
	printf("memcmp result: %i", memcmp(arr1, arr2, 5));
}

void test_length3()
{
	char arr1[] = "qwert0";
	char arr2[] = "qwerty";
	printf("test_length3\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, 6));
	printf("memcmp result: %i", memcmp(arr1, arr2, 6));
}

void test_length4()
{
	char arr1[] = "qwertyyy";
	char arr2[] = "qwerty";
	printf("test_length4\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, 9));
	printf("memcmp result: %i", memcmp(arr1, arr2, 9));
}

void test_length5()
{
	char arr1[] = "qwerty";
	char arr2[] = "qwertyyy";
	printf("test_length5\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, 9));
	printf("memcmp result: %i", memcmp(arr1, arr2, 9));
}

void test_byte_values()
{
	unsigned char s1[] = {127, 128, 0};
	unsigned char s2[] = {127, 128, 12};
	printf("test_byte_values\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(s1, s2, 3));
	printf("memcmp result: %i", memcmp(s1, s2, 3));
}

void test_int_arrays() {
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 2, 3, 4, 5};
	int arr3[] = {1, 2, 3, 4, 9};

	size_t size = sizeof(arr1);

	printf("test_int_arrays - identical\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr2, size));
	printf("memcmp result: %i\n\n", memcmp(arr1, arr2, size));

	printf("test_int_arrays - differing\n");
	printf("ft_memcmp result: %i\n", ft_memcmp(arr1, arr3, size));
	printf("memcmp result: %i\n", memcmp(arr1, arr3, size));
}

void test_warmashine()
{
	printf("test_warmashine\n");
	printf("ft_memcmp result: %i\n", ft_memcmp("t\t", "t\200", 2));
	printf("memcmp result: %i", memcmp("t\t", "t\200", 2));
}

int main()
{
	test_same();
	printf("\n\n");
	fflush(stdout);

	test_bigger();
	printf("\n\n");
	fflush(stdout);

	test_smaller();
	printf("\n\n");
	fflush(stdout);

	test_length1();
	printf("\n\n");
	fflush(stdout);

	test_length2();
	printf("\n\n");
	fflush(stdout);

	test_length3();
	printf("\n\n");
	fflush(stdout);

	test_length4();
	printf("\n\n");
	fflush(stdout);

	test_length5();
	printf("\n\n");
	fflush(stdout);

	test_byte_values();
	printf("\n\n");
	fflush(stdout);

	test_int_arrays();
	printf("\n\n");
	fflush(stdout);

	test_warmashine();
	printf("\n\n");
	fflush(stdout);

	return 0;
}
