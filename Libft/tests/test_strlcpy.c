#include <stdio.h>
#include <bsd/string.h>
#include <stddef.h>
#include "libft.h"

void test_strlcpy_basic() {
    char src[] = "Hello, world!";
    char dst1[20], dst2[20];
    size_t result1 = strlcpy(dst1, src, sizeof(dst1));
    size_t result2 = ft_strlcpy(dst2, src, sizeof(dst2));
    printf("Test Basic Copy\nExpected: Hello, world!\nstrlcpy: %s, %zu\nft_strlcpy: %s, %zu\n\n", dst1, result1, dst2, result2);
}

void test_strlcpy_truncate() {
    char src[] = "Hello, world!";
    char dst1[6], dst2[6]; // Smaller buffer
    size_t result1 = strlcpy(dst1, src, sizeof(dst1));
    size_t result2 = ft_strlcpy(dst2, src, sizeof(dst2));
    printf("Test Truncate Copy\nExpected: Hello\nstrlcpy: %s, %zu\nft_strlcpy: %s, %zu\n\n", dst1, result1, dst2, result2);
}

void test_strlcpy_zero_size() {
    char src[] = "Hello, world!";
    char dst1[20] = {0};  // Initialize with zeros
    char dst2[20] = {0};  // Initialize with zeros

    size_t result1 = strlcpy(dst1, src, 0);  // Zero size
    size_t result2 = ft_strlcpy(dst2, src, 0);

    printf("Test Zero Size\nExpected: \nstrlcpy: %s, %zu\n", dst1, result1);
    printf("ft_strlcpy: %s, %zu\n\n", dst2, result2);
}

void test_strlcpy_exact_buffer() {
    char src[] = "Hello, world!";
    char dst1[14], dst2[14]; // Exact buffer size
    size_t result1 = strlcpy(dst1, src, sizeof(dst1));
    size_t result2 = ft_strlcpy(dst2, src, sizeof(dst2));
    printf("Test Exact Buffer Size\nExpected: Hello, world!\nstrlcpy: %s, %zu\nft_strlcpy: %s, %zu\n\n", dst1, result1, dst2, result2);
}

int main() {
    test_strlcpy_basic();
    test_strlcpy_truncate();
    test_strlcpy_zero_size();
    test_strlcpy_exact_buffer();
    return 0;
}
