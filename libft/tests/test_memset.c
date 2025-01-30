#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main()
{
	char arr[] = "1234";
	int c = 'g';
	size_t n = 2;


	printf("%s\n", arr);
	ft_memset(arr, c, n);
	printf("%s\n", arr);

	char arr2[] = "1234";
	printf("%s\n", arr2);
	memset(arr2, c, n);
	printf("%s\n", arr2);

	int a = 7;

	int *p = &a;
	printf("%i\n", a);
	ft_memset(p, c, n);
	printf("%i\n", a);

	a = 7;
	printf("%i\n", a);
	memset(p, c, n);
	printf("%i\n", a);

	return 0;
}
