#include <stdio.h>

int main()
{
	char arr[] = "abcde";
	printf("Original: %s\n", arr);
	printf("0, 0: %s\n", ft_substr(arr, 0, 0));
	printf("0, 3: %s\n", ft_substr(arr, 0, 3));
	printf("0, 9: %s\n", ft_substr(arr, 0, 9));
	printf("2, 0: %s\n", ft_substr(arr, 2, 0));
	printf("1, 3: %s\n", ft_substr(arr, 1, 3));
	printf("4, 6: %s\n", ft_substr(arr, 4, 6));
	printf("7, 6: %s\n", ft_substr(arr, 7, 6));

	return 0;
}
