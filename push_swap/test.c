#include "push_swap.h"

int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
}

int	apply_push(int *dst, int *src)
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

int	move_all_to_other(int *dst, int *src)
{
	int len;
	int ops;

	ops = 0;
	len = 0;
	len = stack_len(src);
	while (len > 0)
	{
		apply_push(dst, src);
		// printf("pb\n");
		ops++;
		len--;
	}
	return (ops);
}

int	find_closest(int current_min, int current_max, int *stack_A)
{
	int i;
	int distance;

	distance = 0;
	i = 0;
	while (stack_A[i] < current_min || stack_A[i] > current_max)
		i++;
	distance = i + 1;
	i = stack_len(stack_A);
	while (stack_A[i] < current_min || stack_A[i] > current_max)
		i--;
	int j = stack_len(stack_A) - i - 1;
	if(distance < (stack_len(stack_A) - i - 1))
		return (distance - 1);
	return (i);
}

int	find_gap(int nb, int *stack_B)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(stack_B[i] != -1)
	{
		if(nb - stack_B[i] > 0 && (nb - stack_B[i] < nb - stack_B[j]))
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
	if(i == 0)
		i = stack_len(stack_B);
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

int	algorithm(int amount, int *stack_A, int *stack_B)
{
	int	chunck_size;
	int	ops;
	int	current_max;
	int	current_min;
	// int	closest_nb_position;
	int i = 0;
	int j = 0;
	current_max = 0;
	current_min = 0;
	ops = 0;

	chunck_size = stack_len(stack_A) / 3;
	chunck_size = 3;
	current_max = chunck_size - 1;
	current_min = current_max - (chunck_size - 1);
	// while (current < amount)
	// 	closest_nb_position = find_closest_nb_to_end(current, stack_A);
	while (current_max < amount)
	{
		j = chunck_size;
		while(j > 0)
		{
			i = find_closest(current_min, current_max, stack_A);
			if ((i >= stack_len(stack_A) / 2))
			{
				while ((stack_len(stack_A) - (i + 1)) > 0)
				{
					apply_rotation(stack_A);
					ops++;
					// printf("rr\n");
					i++;
				}
			}
			else
			{
				while (i >= 0)
				{
					apply_reverse_rotation(stack_A);
					ops++;
					// printf("rr\n");
					i--;
				}
			}
			ops += rotate_B(stack_A[stack_len(stack_A) - 1], stack_B);
			apply_push(stack_B, stack_A);
			if (stack_B[stack_len(stack_B) - 1] < stack_B[stack_len(stack_B) - 2])
				apply_rotation(stack_B);
			ops++;
			// printf("pa\n");
			j--;
		}
		current_max += chunck_size;
		current_min += chunck_size;
	}
	ops += move_all_to_other(stack_A, stack_B);
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
    int values[] = {1, 0, 2, -1};
    int num_values = sizeof(values) / sizeof(values[0]);

    for (i = 0; i < num_values; i++)
        stackA[i] = values[i];

	int *stackB = malloc(1000 * sizeof(int));

    if (!stackB) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int valuesb[] = {-1};
    num_values = sizeof(values) / sizeof(values[0]);

    for (i = 0; i < num_values; i++)
        stackB[i] = valuesb[i];

	i = 0;
	while (stackA[i] != -1)
		printf("%d ", stackA[i++]);
	printf("%d ", stackA[i]);
	printf("\n");
	i = 0;
	while (stackB[i] != -1)
		printf("%d ", stackB[i++]);
	printf("%d ", stackB[i]);
	printf("\n");
	printf("\n");

	int ops = algorithm(stack_len(stackA), stackA, stackB);

	i = 0;
	while (stackA[i] != -1)
		printf("%d ", stackA[i++]);
	printf("%d ", stackA[i]);
	printf("\n");
	i = 0;
	while (stackB[i] != -1)
		printf("%d ", stackB[i++]);
	printf("%d ", stackB[i]);
	printf("\n\n");
	printf("Operations: %d", ops);
	return 0;
}
