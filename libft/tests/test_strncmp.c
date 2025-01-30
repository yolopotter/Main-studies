#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main()
{
	char src[] = "1234";
	char src1[] = "1234";
	char src2[] = "123";
	char src3[] = "12345";
	char src4[] = "334";
	size_t n = 5;


	printf("%s, %s\n", src, src1);
	printf("%i\n", ft_strncmp(src, src1, n));

	printf("%s, %s\n", src, src1);
	printf("%i\n", strncmp(src, src1, n));

	printf("----------------------\n");

	printf("%s, %s\n", src2, src1);
	printf("%i\n", ft_strncmp(src2, src1, n));

	printf("%s, %s\n", src2, src1);
	printf("%i\n", strncmp(src2, src1, n));

	printf("----------------------\n");

	printf("%s, %s\n", src3, src2);
	printf("%i\n", ft_strncmp(src3, src2, n));

	printf("%s, %s\n", src3, src2);
	printf("%i\n", strncmp(src3, src2, n));

	printf("----------------------\n");

	printf("%s, %s\n", src4, src2);
	printf("%i\n", ft_strncmp(src4, src2, n));

	printf("%s, %s\n", src4, src2);
	printf("%i\n", strncmp(src4, src2, n));

	printf("----------------------\n");

	printf("'escape'200, 'escape'0 \n");
	printf("%i\n", ft_strncmp("test\200", "test\0", 6));

	printf("'escape'200, 'escape'0 \n");
	printf("%i\n", strncmp("test\200", "test\0", 6));

	printf("----------------------\n");
}
