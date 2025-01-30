#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main()
{
    char src[] = "123456789";
    size_t n = 5;

    printf("%s\n", src);
    memmove(src, src + 2, n);
    printf("%s\n\n", src);

    char src2[] = "123456789";
	printf("%s\n", src2);
    ft_memmove(src2, src2 + 2, n);
    printf("%s\n\n", src2);

    char src3[] = "123456789";
	printf("%s\n", src3);
    memmove(src3 + 2, src3, n);
    printf("%s\n\n", src3);

    char src4[] = "123456789";
	printf("%s\n", src4);
    ft_memmove(src4 + 2, src4, n);
    printf("%s\n\n", src4);

    return 0;
}


/*
int main()
{
	char src[] = "123456789";
	size_t n = 5;


	printf("%s\n", src);
	memmove(src + 2, src, n);
	printf("%s\n\n", src);

	char src2[] = "1234";
	char dest2[] = "abcd";
	printf("%s, %s\n", src2, dest2);
	memmove(src + 2, src2, n);
	printf("%s, %s\n\n", src2, dest2);

	int a = 7;
	int b = 8;

	int *p1 = &a;
	int *p2 = &b;
	n = 1;
	printf("%i, %i\n", *p1, *p2);
	ft_memmove(p1, p2, n);
	printf("%i, %i\n\n", *p1, *p2);

	a = 7;
	b = 8;
	printf("%i, %i\n", *p1, *p2);
	memmove(p1, p2, n);
	printf("%i, %i\n\n", *p1, *p2);

	return 0;
}
*/
