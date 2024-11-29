#include "push_swap.h"

int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
}

int	apply_reverse_rotation(int *stack)
{
	int	i;
	int	len;
	int	temp;

	len = stack_len(stack);
	if (len == 0)
		return (1);
	if (!stack)
		return (1);
	temp = stack[0];
	i = 0;
	while(i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	return (0);
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
//Tarkasta toimiiko tää nyt oikein
int	find_gap(int nb, int *stack_B)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while(stack_B[i] != -1)
	{
		if (nb < stack_B[i])
			return (stack_len(stack_B));
		if (nb - stack_B[i] < nb - stack_B[j])
			j = i;
		i++;
	}
	return (j);
}

int	rotate_B(int nb, int *stack_B)
{
	int	i;
	int	ops;

	i = 0;
	ops = 0;
	i = find_gap(nb, stack_B);
	if ((i >= stack_len(stack_B) / 2))
	{
		while ((stack_len(stack_B) - (i + 1)) > 0)
		{
			apply_rotation(stack_B);
			ops++;
			// printf("rr\n");
			i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			apply_reverse_rotation(stack_B);
			ops++;
			// printf("rr\n");
			i--;
		}
	}
	return (ops);
}

int main()
{
	int i = 0;
	int *stackA = malloc(1000 * sizeof(int));

    if (!stackA) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int values[] = {0, 2, -1};
    int num_values = sizeof(values) / sizeof(values[0]);

    for (i = 0; i < num_values; i++)
        stackA[i] = values[i];

	int	current_max = 5;
	int	current_min = 3;

	i = rotate_B(1, stackA);
	printf("%d\n", i);
	i = 0;
	while (stackA[i] != -1)
		printf("%d ", stackA[i++]);
	printf("%d ", stackA[i]);
	printf("\n\n");
	return 0;
}
