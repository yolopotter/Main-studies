
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void test_memcpy_one_NULL(void)
{
    //ft_memcpy(((void*)0), "segfaulter tu dois", 17);

	//ft_memcpy("            ", ((void*)0), 17);
}

void test_memcpy_both_NULL(void)
{
    void *result;

    // Test ft_memcpy with NULL pointers
    result = ft_memcpy(((void*)0), ((void*)0), 3);
    if (result == NULL)
        printf("ft_memcpy: Result is NULL (expected behavior).\n");
    else
        printf("ft_memcpy: Unexpected result.\n");
}

int main()
{
	char src[] = "1234";
	char dest[] = "abcd";
	size_t n = 1;


	printf("%s, %s\n", src, dest);
	ft_memcpy(dest+3, src, n);
	printf("%s, %s\n\n", src, dest);

	char src2[] = "1234";
	char dest2[] = "abcd";
	printf("%s, %s\n", src2, dest2);
	memcpy(dest2+3, src2, n);
	printf("%s, %s\n\n", src2, dest2);

	int a = 7;
	int b = 8;

	int *p1 = &a;
	int *p2 = &b;
	n = 1;
	printf("%i, %i\n", *p1, *p2);
	ft_memcpy(p1+3, p2, n);
	printf("%i, %i\n\n", *p1, *p2);

	a = 7;
	b = 8;
	printf("%i, %i\n", *p1, *p2);
	memcpy(p1+3, p2, n);
	printf("%i, %i\n\n", *p1, *p2);

    char csrc[] = "Geeksfor";
    ft_memcpy(csrc + 5, csrc, n);
    printf("%s\n", csrc);

	char csrc1[] = "Geeksfor";
    memcpy(csrc1 + 5, csrc1, n);
    printf("%s\n", csrc1);

	//test_memcpy_both_NULL();
	//test_memcpy_one_NULL();

	return 0;
}
