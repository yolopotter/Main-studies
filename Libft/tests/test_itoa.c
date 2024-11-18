#include <stdio.h>
#include "libft.h"

void	test_zero()
{
	printf("Expected: %i\n ft_itoa: %s\n\n", 0, ft_itoa(0));
}

void	test_negative()
{
	printf("Expected: %i\n ft_itoa: %s\n\n", -8437564, ft_itoa(-8437564));
}

void	test_positive()
{
	printf("Expected: %i\n ft_itoa: %s\n\n", 8437564, ft_itoa(8437564));
}
void	test_war1()
{
	printf("Expected: %i\n ft_itoa: %s\n\n", 10, ft_itoa(10));
}

void	test_war2()
{
	printf("Expected: %li\n ft_itoa: %s\n\n", -2147483648, ft_itoa(-2147483648LL));
}

void	test_max_positive()
{
	printf("Expected: %i\n ft_itoa: %s\n\n", 2147483647, ft_itoa(2147483647));
}

int	main()
{
	test_zero();
	test_negative();
	test_positive();
	test_war1();
	test_war2();
	test_max_positive();
	return 0;
}
