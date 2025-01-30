#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

int main()
{
	int i =	ft_isalnum('y');
	printf("%i\n", i);
	i =	isalnum('y');
	printf("%i\n\n", i);

	i =	ft_isalnum(8);
	printf("%i\n", i);
	i =	isalnum(8);
	printf("%i\n\n", i);

	i =	ft_isalnum('D');
	printf("%i\n", i);
	i =	isalnum('D');
	printf("%i\n\n", i);

	i =	ft_isalnum('8');
	printf("%i\n", i);
	i =	isalnum('8');
	printf("%i\n\n", i);
}
