#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
}
int	apply_swap(int *src)
{
	int temp;
	int len;

	len = stack_len(src);
	if (!src || len == 0)
		return (0);
	if (len == 1)
		return (1);
	temp = src[len - 1];
	src[len - 1] = src[len - 2];
	src[len - 2] = temp;
	return (1);
}

int	apply_rotation(int *stack)
{
	int	len;
	int	temp;

	len = stack_len(stack);
	if (len == 0)
		return (1);
	if (!stack)
		return (1);
	temp = stack[len - 1];
	while(len > 0)
	{
		stack[len - 1] = stack[len - 2];
		len--;
	}
	stack[0] = temp;
	return (0);
}

static int	find_max(int *stack)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while(stack[i] != -1)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

static int	find_min(int *stack)
{
	int	i;
	int	min;

	i = 0;
	if (stack_len(stack) == 0)
		return (0);
	min = stack[i];
	while(stack[i] != -1)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	size_mini_algorithm(int *stack_A)
{
	int max;
	int min;
	int ops;

	max = find_max(stack_A);
	min = find_min(stack_A);
	ops = 0;
	if ((stack_A[0] == min && stack_A[2] == max) ||
		(stack_A[2] == min && stack_A[1] == max) ||
		stack_A[0] == max)
	{
		apply_swap(stack_A);
		write(1, "sa\n", 3);
		ops += 1;
	}
	while (stack_A[0] != max)
	{
		apply_rotation(stack_A);
		write(1, "ra\n", 3);
		ops += 1;
	}
	return (ops);
}

void print_stack(int *stack, int size) {
    for (int i = 0; i < size; i++) {
        if (stack[i] == -1) {
            printf("-1");
        } else {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void test_size_mini_algorithm(int *stack, int size) {
    printf("\n--- Testing size_mini_algorithm ---\n");
    printf("Initial stack: ");
    print_stack(stack, size);

    int ops = size_mini_algorithm(stack);

    printf("Final stack: ");
    print_stack(stack, size);
    printf("Total operations: %d\n", ops);
}

int main() {
    // All permutations of 0, 1, 2, with -1 as the last index
    int test_cases[][4] = {
        {0, 1, 2, -1},
        {0, 2, 1, -1},
        {1, 0, 2, -1},
        {1, 2, 0, -1},
        {2, 0, 1, -1},
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        test_size_mini_algorithm(test_cases[i], 4);
    }

    return 0;
}


