#include "push_swap.h"

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
int	apply_push(int *dst, int *src)
{
	int	len_src;
	int	len_dst;

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
	while (src[0] != 0)
	{
		apply_rotation(src);
		ops++;
	}
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
	// int j = stack_len(stack_A) - i - 1;
	if(distance < (stack_len(stack_A) - i - 1))
		return (distance - 1);
	return (i);
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

int	find_gap(int nb, int *stack_B)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = find_max(stack_B);
	min = find_min(stack_B);
	while(stack_B[i] != -1)
	{
		if (nb > max || nb < min)
		{
			i = 0;
			while (stack_B[i] != -1)
			{
				if(stack_B[i] == max)
					return (i);
				i++;
			}
		}
		if (nb > stack_B[i] && nb < stack_B[i + 1])
			return (i);
		i++;
	}
	return (i);
}

int	rotate(int ra, int rb, int *stack_A, int *stack_B)
{
	int	ops;

	ops = 0;
	while (ra < 0 && rb < 0)
	{
		apply_reverse_rotation(stack_A);
		apply_reverse_rotation(stack_B);
		rb++;
		ra++;
		// write(1, "rrr\n", 4);
		ops += 1;
	}
	while (ra > 0 && rb > 0)
	{
		apply_rotation(stack_A);
		apply_rotation(stack_B);
		rb--;
		ra--;
		// write(1, "rr\n", 3);
		ops += 1;
	}
	// cut
	while (ra > 0 && rb < 0)
	{
		apply_reverse_rotation(stack_B);
		apply_rotation(stack_A);
		rb++;
		ra--;
		// write(1, "rrb\n", 4);
		// write(1, "ra\n", 3);
		ops += 2;
	}
	while (ra < 0 && rb > 0)
	{
		apply_rotation(stack_B);
		apply_reverse_rotation(stack_A);
		rb--;
		ra++;
		// write(1, "rb\n", 4);
		// write(1, "rra\n", 4);
		ops += 2;
	}
	//cut
	while (ra == 0 && rb < 0)
	{
		apply_reverse_rotation(stack_B);
		rb++;
		// write(1, "rrb\n", 4);
		ops += 1;
	}
	while (ra < 0 && rb == 0)
	{
		apply_reverse_rotation(stack_A);
		ra++;
		// write(1, "rra\n", 4);
		ops += 1;
	}
	while (ra == 0 && rb > 0)
	{
		apply_rotation(stack_B);
		rb--;
		// write(1, "rb\n", 3);
		ops += 1;
	}
	while (ra > 0 && rb == 0)
	{
		apply_rotation(stack_A);
		ra--;
		// write(1, "ra\n", 3);
		ops += 1;
	}
	return (ops);
}

int	CALCULATE_find_current_position(int current, int *stack_A)
{
	int i;

	i = 0;
	while (stack_A[i] != -1)
	{
		if (stack_A[i] == current)
			return (i);
		i++;
	}
	return (-1);
}

int	CALCULATE_rotation_or_reverse(int pos, int *stack)
{
	int rotations;

	rotations = 0;
	if ((pos >= stack_len(stack) / 2))
	{
		while ((stack_len(stack) - (pos + 1)) > 0)
		{
			pos++;
			rotations++;
		}
	}
	else
	{
		while (pos >= 0)
		{
			pos--;
			rotations--;
		}
	}
	return (rotations);
}

int	CALCULATE_find_smallest_current(int c_min, int c_max, int *i, int *stack_A)
{
	while (stack_A[*i] != -1)
	{
		if (stack_A[*i] >= c_min && stack_A[*i] <= c_max)
		{
			return (stack_A[(*i)++]);
		}
		(*i)++;
	}
	return (-1);
}

int	CALCULATE_price(int ra, int rb)
{
	int delta;
	int price;

	delta = ra - rb;
	if ((ra > 0 && rb > 0) || (ra < 0 && rb < 0))
		price = abs(delta) + min(abs(ra), abs(rb));
	else
		price = abs(delta);
	return (price);
}

int	CALCULATE_find_cheapest_nb(int c_min, int c_max, int *stack_A, int *stack_B)
{
	int	i;
	int	current_nb;
	int	position_A;
	int	position_B;
	int cheapest_position;
	int	ra;
	int	rb;
	int	price;
	int cheapest;

	i = 0;
	cheapest = 1000000;
	while (stack_A[i] != -1) // seems to be working perfectly now. Next thing to build is actual rrr and rr.
	{
		current_nb = CALCULATE_find_smallest_current(c_min, c_max, &i, stack_A);
		if (current_nb == -1)
			break ;
		position_A = CALCULATE_find_current_position(current_nb, stack_A);
		ra = CALCULATE_rotation_or_reverse(position_A, stack_A);
		position_B = find_gap(current_nb, stack_B);
		rb = CALCULATE_rotation_or_reverse(position_B, stack_B);
		price = CALCULATE_price(ra, rb);
		if (price < cheapest)
		{
			cheapest_position = position_A;
			cheapest = price;
		}
	}
	// printf("cheapest %i\n", cheapest);
	return (cheapest_position);
}

int	size_mini_algorithm(int amount, int *stack) //this needs testing, just created for cases of 1 and 2 numbers, maybe case for 0 needed
{
	int max;
	int min;
	int ops;

	ops = 0;
	if (amount == 1)
		return (ops);
	if (amount == 2);
	{
		if (stack[0] < stack[1])
		{
			apply_swap(stack);
			write(1, "sa\n", 3);
			ops += 1;
		}
		return (ops);
	}
	max = find_max(stack);
	min = find_min(stack);
	if ((stack[0] == min && stack[2] == max) ||
		(stack[2] == min && stack[1] == max) ||
		stack[0] == max)
	{
		apply_swap(stack);
		write(1, "sa\n", 3);
		ops += 1;
	}
	while (stack[0] != max)
	{
		apply_rotation(stack);
		write(1, "ra\n", 3);
		ops += 1;
	}
	return (ops);
}

int	size_small_algorithm(int amount, int *stack_A, int *stack_B) // make it work until 6 numbers, max operations 12.
{
	int	min;

	min = find_min(stack_A);
}

int	size_big_algorithm(int chunck_size, int amount, int *stack_A, int *stack_B)
{
	// int	chunck_size;
	int	ops;			//amount of operations
	int	current_max;
	int	current_min;
	int	position = 0; //position	i;
	int	current_nb;
	int	position_A;
	int	position_B;
	int	ra;
	int	rb;
	int	j = 0;
	ops = 0;

	// chunck_size = stack_len(stack_A) / 17;
	// chunck_size = 46; //chunk size around 40 for 500 numbers is optimal.
	current_max = chunck_size - 1;
	current_min = current_max - (chunck_size - 1);
	while (current_min < amount)
	{
		if (current_max > amount - 1) //check for situation if there is lesst than full chunck left
			current_max = amount - 1;
		j = current_max - current_min + 1;
		while(j > 0)
		{
			position = CALCULATE_find_cheapest_nb(current_min, current_max, stack_A, stack_B);
			current_nb = stack_A[position];
			position_A = CALCULATE_find_current_position(current_nb, stack_A);
			ra = CALCULATE_rotation_or_reverse(position_A, stack_A);
			position_B = find_gap(current_nb, stack_B);
			rb = CALCULATE_rotation_or_reverse(position_B, stack_B);
			// printf("ra %i\n", ra);
			// printf("rb %i\n", rb);
			// printf("current_nb %i\n", current_nb);
			ops += rotate(ra, rb, stack_A, stack_B);
			apply_push(stack_B, stack_A);
			ops++;
			// printf("pa\n");
			j--;
		}
		current_max += chunck_size;
		if (current_max > amount - 1)
			current_max = amount - 1;
		current_min += chunck_size;
	}
	ops += move_all_to_other(stack_A, stack_B);
	return (ops);
}

int	algorithm(int chunck_size, int amount, int *stack_A, int *stack_B)
{
	// if(is_sorted(stack_A))
	// 	return (0);
	if (amount > 15)
		return (size_big_algorithm(chunck_size, amount, stack_A, stack_B));
	else if (amount > 3)
		return (size_small_algorithm(amount, stack_A, stack_B));
	else if (amount > 0)
		return (size_mini_algorithm(amount, stack_A));
	return (-1);
}

int main()
{
	int i = 0;

	int chunck_size = 1;
	while(chunck_size < 101)
	{
		int *stackA = malloc(1000 * sizeof(int));
		int values[] = {15, 93, 84, 29, 69, 83, 73, 41, 80, 71, 81, 20, 42, 52, 1, 50, 70, 95, 7, 68, 35, 62, 2, 40, 6, 3, 43, 23, 89, 51, 25, 9, 55, 53, 14, 67, 5, 99, 4, 22, 24, 66, 65, 59, 48, 8, 63, 39, 90, 33, 46, 76, 45, 92, 26, 36, 58, 56, 54, 34, 18, 75, 38, 13, 12, 37, 94, 16, 28, 96, 79, 61, 77, 44, 21, 32, 85, 19, 31, 57, 10, 97, 74, 82, 0, 72, 91, 47, 78, 87, 98, 11, 88, 86, 49, 30, 27, 64, 17, 60, -1};
		int num_values = sizeof(values) / sizeof(values[0]);

		for (i = 0; i < num_values; i++)
		{
			stackA[i] = values[i];
		}

		int *stackB = malloc(1000 * sizeof(int));

		if (!stackB) {
			printf("Memory allocation failed\n");
			return 1;
		}
		int valuesb[] = {-1};
		num_values = sizeof(values) / sizeof(values[0]);

		for (i = 0; i < num_values; i++)
		{
			stackB[i] = valuesb[i];
		}
		int ops = algorithm(chunck_size, stack_len(stackA), stackA, stackB);
		printf("chunck size %i, Operations: %d\n", chunck_size, ops);
		free(stackA);
		free(stackB);
		chunck_size++;
	}

	// i = 0;
	// while (stackA[i] != -1)
	// 	printf("%d ", stackA[i++]);
	// printf("%d ", stackA[i]);
	// printf("\n");
	// i = 0;
	// while (stackB[i] != -1)
	// 	printf("%d ", stackB[i++]);
	// printf("%d ", stackB[i]);
	// printf("\n\n");
	return 0;
}
