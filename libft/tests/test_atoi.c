
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>

int main()
{
	printf("Minimum and maximum values of various data types:\n");
    printf("int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("long:   %ld to %ld\n\n", LONG_MIN, LONG_MAX);

	int i =	ft_atoi("-123456");
	printf("%i\n", i);
	i =	atoi("-123456");
	printf("%i\n\n", i);

	i =	ft_atoi("-2147483648");
	printf("%i\n", i);
	i =	atoi("-2147483648");
	printf("%i\n\n", i);

	i =	ft_atoi("9223372036854775808");
	printf("%i\n", i);
	i =	atoi("9223372036854775808");
	printf("%i\n\n", i);

	i =	ft_atoi("-9223372036854775810");
	printf("%i\n", i);
	i =	atoi("-9223372036854775810");
	printf("%i\n\n", i);

	i =	ft_atoi("2147483647");
	printf("%i\n", i);
	i =	atoi("2147483647");
	printf("%i\n\n", i);

	i =	ft_atoi("  0");
	printf("%i\n", i);
	i =	atoi("  0");
	printf("%i\n\n", i);

	i =	ft_atoi("   -+1234");
	printf("%i\n", i);
	i =	atoi("   -+1234");
	printf("%i\n\n", i);

	i =	ft_atoi("1233adf3456");
	printf("%i\n", i);
	i =	atoi("1233adf3456");
	printf("%i\n\n", i);

	return 0;
}
