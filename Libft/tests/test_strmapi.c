#include <stdio.h>
#include <ctype.h>
#include "libft.h"

char identity(unsigned int i, char c) {
    (void)i;
    return c;
}

char index_increment(unsigned int i, char c) {
    return c + i;
}

char to_lowercase(unsigned int i, char c) {
	(void)i;
	return tolower((unsigned char)c);
}

char to_uppercase(unsigned int i, char c)
{
	(void)i;
	return toupper((unsigned char) c);
}

void	test_identity_function()
{
	printf("Identity\n");
	char arr[] = "abCDe123";
	char *result = ft_strmapi(arr, identity);
	printf("Original: %s\n", arr);
	printf("Edited: %s\n\n", result);
	free(result);
}

void	test_index_modifiation()
{
	printf("+i index\n");
	char arr[] = "abCDe123";
	char *result = ft_strmapi(arr, index_increment);
	printf("Original: %s\n", arr);
	printf("Edited: %s\n\n", result);
	free(result);
}

void	test_empty_string()
{
	printf("Empty string\n");
	char arr[] = "";
	char *result = ft_strmapi(arr, index_increment);
	printf("Original: %s\n", arr);
	printf("Edited: %s\n\n", result);
	free(result);
}

void	test_NULL()
{
	printf("NULL test\n");
	char *result = ft_strmapi(NULL, index_increment);
    if (result)
	{
        printf("Result: %s\n", result);
        free(result);
    }
	else
        printf("Result: NULL\n\n");
}

void	test_to_lower()
{
	printf("To lower\n");
	char arr[] = "abCDe123";
	char *result = ft_strmapi(arr, to_lowercase);
	printf("Original: %s\n", arr);
	printf("Edited: %s\n\n", result);
	free(result);
}

void	test_to_upper()
{
	printf("To upper\n");
	char arr[] = "abCDe123";
	char *result = ft_strmapi(arr, to_uppercase);
	printf("Original: %s\n", arr);
	printf("Edited: %s\n\n", result);
	free(result);
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
