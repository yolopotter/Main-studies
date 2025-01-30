#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void identity(unsigned int i, char *c) {
    (void)i;
    (void)*c;
}

void index_increment(unsigned int i, char *c) {
    *c += i;
}

void to_lowercase(unsigned int i, char *c) {
	(void)i;
	*c = tolower((unsigned char) *c);
}

void to_uppercase(unsigned int i, char *c)
{
	(void)i;
	*c = toupper((unsigned char) *c);
}

void	test_identity_function()
{
	printf("Identity\n");
	char arr[] = "abCDe123";
	printf("Original: %s\n", arr);
	ft_striteri(arr, identity);
	printf("Edited: %s\n\n", arr);
}

void	test_index_modifiation()
{
	printf("+i index\n");
	char arr[] = "abCDe123";
	printf("Original: %s\n", arr);
	ft_striteri(arr, index_increment);
	printf("Edited: %s\n\n", arr);
}

void	test_empty_string()
{
	printf("Empty string\n");
	char arr[] = "";
	printf("Original: %s\n", arr);
	ft_striteri(arr, index_increment);
	printf("Edited: %s\n\n", arr);
}

void	test_NULL()
{
	printf("NULL test\n");
	ft_striteri(NULL, index_increment);
	printf("Test completed (no crash means success).\n\n");
}

void	test_to_lower()
{
	printf("To lower\n");
	char arr[] = "abCDe123";
	printf("Original: %s\n", arr);
	ft_striteri(arr, to_lowercase);
	printf("Edited: %s\n\n", arr);
}

void	test_to_upper()
{
	printf("To upper\n");
	char arr[] = "abCDe123";
	printf("Original: %s\n", arr);
	ft_striteri(arr, to_uppercase);
	printf("Edited: %s\n\n", arr);
}

int main()
{
	test_identity_function();
	test_index_modifiation();
	test_empty_string();
	test_NULL();
	test_to_lower();
	test_to_upper();
	return 0;
}
