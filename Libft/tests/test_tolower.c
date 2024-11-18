#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main()
{
	char c = 'a';
	printf("%c -> %c\n", c, ft_tolower(c));
	c = 'a';
	printf("%c -> %c\n", c, tolower(c));

	printf("----------------------\n");

	c = 'K';
	printf("%c -> %c\n", c, ft_tolower(c));
	c = 'K';
	printf("%c -> %c\n", c, tolower(c));

	printf("----------------------\n");

	c = '0';
	printf("%c -> %c\n", c, ft_tolower(c));
	c = '0';
	printf("%c -> %c\n", c, tolower(c));

	printf("----------------------\n");

	c = '?';
	printf("%c -> %c\n", c, ft_tolower(c));
	c = '?';
	printf("%c -> %c\n", c, tolower(c));
	return 0;
}
