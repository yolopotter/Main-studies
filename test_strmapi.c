#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the ft_strmapi function
char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
    if (!s || !f) return NULL;

    size_t len = strlen(s);
    char *new_str = malloc(len + 1); // Allocate memory for new string
    if (!new_str) return NULL;

    for (unsigned int i = 0; i < len; i++) {
        new_str[i] = f(i, s[i]); // Apply the function to each character
    }
    new_str[len] = '\0'; // Null-terminate the new string

    return new_str;
}

// Define a sample transformation function
char my_transform_function(unsigned int index, char c) {
    if (index % 2 == 0)
        return toupper(c); // Uppercase for even indices
    else
        return tolower(c); // Lowercase for odd indices
}

int main() {
    char *original = "Hello, World!";
    char *transformed = ft_strmapi(original, my_transform_function);

    if (transformed) {
        printf("Original: %s\n", original);
        printf("Transformed: %s\n", transformed);
        free(transformed); // Free allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
