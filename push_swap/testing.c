#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int	is_sorted(int *stack)
{
	int	i;

	i = 1;
	while (stack[i] != -1)
	{
		if (stack[i] > stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void test_is_sorted(int *stack, const char *test_name) {
    printf("--- %s ---\n", test_name);
    printf("Stack: ");
    for (int i = 0; stack[i] != -1; i++) {
        printf("%d ", stack[i]);
    }
    printf("-1\n");

    int result = is_sorted(stack);
    printf("Is sorted: %s\n\n", result ? "Yes" : "No");
}

int main() {
    // Test cases
    int stack1[] = {-1};                    // Empty stack
    int stack2[] = {5, -1};                 // Single element
    int stack3[] = {1, 2, 3, -1};           // Sorted stack
    int stack4[] = {3, 2, 1, -1};           // Reverse sorted stack
    int stack5[] = {1, 3, 2, -1};           // Unsorted stack
    int stack6[] = {1, 2, 3, -1};        // Duplicate elements (sorted)
    int stack7[] = {3, 2, 3, 1, -1};        // Unsorted with duplicates

    // Run tests
    test_is_sorted(stack1, "Test 1: Empty Stack");
    test_is_sorted(stack2, "Test 2: Single Element");
    test_is_sorted(stack3, "Test 3: Sorted Stack");
    test_is_sorted(stack4, "Test 4: Reverse Sorted Stack");
    test_is_sorted(stack5, "Test 5: Unsorted Stack");
    test_is_sorted(stack6, "Test 6: Sorted Stack with Duplicates");
    test_is_sorted(stack7, "Test 7: Unsorted Stack with Duplicates");

    return 0;
}
