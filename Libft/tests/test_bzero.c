#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include "libft.h"

int main()
{
	char arr[] = "1234";
	int c = 2;

	printf("%s\n", arr);
	ft_bzero(arr, c);
	printf("%s\n", arr);

	char arr2[] = "1234";
	printf("%s\n", arr2);
	bzero(arr2, c);
	printf("%s\n", arr2);

	int a = 7;

	int *p = &a;
	printf("%i\n", a);
	ft_bzero(p, c);
	printf("%i\n", a);

	a = 7;
	printf("%i\n", a);
	bzero(p, c);
	printf("%i\n", a);

	return 0;
}
