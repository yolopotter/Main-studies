
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_temp;
	const unsigned char	*src_temp;

	if (!dest && !src)
		return (0);
	i = 0;
	dst_temp = (unsigned char *)dest;
	src_temp = (const unsigned char *)src;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


size_t strlcat(char *dst, const char *src, size_t size);

void test_strlcat_basic() {
    char src[] = " world!";
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";

    size_t result1 = strlcat(dst1, src, sizeof(dst1));
    size_t result2 = ft_strlcat(dst2, src, sizeof(dst2));

    printf("Test Basic Concatenation\nExpected: Hello world!\nstrlcat: %s, %zu\nft_strlcat: %s, %zu\n\n", dst1, result1, dst2, result2);
}

void test_strlcat_truncate() {
    char src[] = " world!";
    char dst1[10] = "Hello";
    char dst2[10] = "Hello";

    size_t result1 = strlcat(dst1, src, sizeof(dst1));
    size_t result2 = ft_strlcat(dst2, src, sizeof(dst2));

    printf("Test Truncate Concatenation\nExpected: Hello wor\nstrlcat: %s, %zu\nft_strlcat: %s, %zu\n\n", dst1, result1, dst2, result2);
}

void test_strlcat_zero_size() {
    char src[] = " world!";
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";

    size_t result1 = strlcat(dst1, src, 0);  // Zero size
    size_t result2 = ft_strlcat(dst2, src, 0);

    printf("Test Zero Size\nExpected: Hello\nstrlcat: %s, %zu\nft_strlcat: %s, %zu\n\n", dst1, result1, dst2, result2);
}

void test_strlcat_test() {
    char src[] = "def";
    char dst1[13] = "abc";
    char dst2[13] = "abc";

    size_t result1 = strlcat(dst1, src, 8);
    size_t result2 = ft_strlcat(dst2, src, 8);

    printf("Test Exact Buffer Size\nExpected: abcdef\nstrlcat: %s, %zu\nft_strlcat: %s, %zu\n\n", dst1, result1, dst2, result2);
}

void test_strlcat_test2() {
    char src[] = "d";
    char dst1[13] = "abc";
    char dst2[13] = "abc";

    size_t result1 = strlcat(dst1, src, 8);
    size_t result2 = ft_strlcat(dst2, src, 8);

    printf("Test Exact Buffer Size\nExpected: abcd\nstrlcat: %s, %zu\nft_strlcat: %s, %zu\n\n", dst1, result1, dst2, result2);
}

int main() {
    test_strlcat_basic();
    printf("\n");

    test_strlcat_truncate();
    printf("\n");

    test_strlcat_zero_size();
    printf("\n");

    test_strlcat_test();
    printf("\n");

    test_strlcat_test2();
    printf("\n");

    return 0;
}


