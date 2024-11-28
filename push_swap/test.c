#include "push_swap.h"

int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
}

int	push(int *dst, int *src)
{
	int	len_src;
	int	len_dst;
	int	temp;

	if (!src || !dst)
		return (0);
	len_src = stack_len(src);
	if (len_src == 0)
		return (0);
	len_dst = stack_len(dst);
	dst[len_dst + 1] = -1;
	dst[len_dst] = src[len_src - 1];
	src[len_src - 1] = -1;
	return (1);
}

int main()
{
	int i = 0;
	int *stack1 = malloc(100 * sizeof(int)); // Allocate space for 5 integers

    if (!stack1) { // Check if malloc succeeded
        printf("Memory allocation failed\n");
        return 1;
    }
    stack1[0] = 1;
    stack1[1] = 2;
    stack1[2] = 3;
    stack1[3] = 4;
    stack1[4] = -1; // Assign values

	int *stack2 = malloc(100 * sizeof(int)); // Allocate space for 5 integers

    if (!stack2) { // Check if malloc succeeded
        printf("Memory allocation failed\n");
        return 1;
    }
    stack2[0] = 9;
    stack2[1] = 8;
    stack2[2] = 7;
    stack2[3] = -1; // Assign values

	i = 0;
	while (stack1[i] != -1)
		printf("%d ", stack1[i++]);
	printf("%d ", stack1[i]);
	printf("\n");
	i = 0;
	while (stack2[i] != -1)
		printf("%d ", stack2[i++]);
	printf("%d ", stack2[i]);
	printf("\n");
	printf("\n");

	push(stack1, stack2);
	push(stack1, stack2);
	push(stack1, stack2);
	push(stack1, stack2);

	for (int i = 0; i < 9; i++)
        push(stack2, stack1);

	i = 0;
	while (stack1[i] != -1)
		printf("%d ", stack1[i++]);
	printf("%d ", stack1[i]);
	printf("\n");
	i = 0;
	while (stack2[i] != -1)
		printf("%d ", stack2[i++]);
	printf("%d ", stack2[i]);
	printf("\n");

	return 0;
}
