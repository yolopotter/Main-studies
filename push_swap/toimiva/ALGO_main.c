#include "push_swap.h"

int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
}

int	find_max(int *stack)
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

int	find_min(int *stack)
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
	int	min;

	ops = 0;
	len = 0;
	min = find_min(src);
	len = stack_len(src);
	while (src[0] != min)
	{
		apply_rotation(src);
		ops++;
	}
	while (len > 0)
	{
		apply_push(dst, src);
		// write(1, "pb\n", 3);
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
	while (stack_A[i] != -1)
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

int	size_mini_under_3(int amount, int *stack)
{
	if (amount <= 0)
		return (-1);
	else if (amount == 1)
		return (0);
	else
	{
		if (stack[0] < stack[1])
		{
			apply_swap(stack);
			write(1, "sa\n", 3);
			return (1);
		}
		return (0);
	}
}

int	size_mini_algorithm(int amount, int *stack)
{
	int max;
	int min;
	int ops;

	ops = 0;
	if(is_sorted(stack))
		return (0);
	if (amount < 3)
		return (size_mini_under_3(amount, stack));
	max = find_max(stack);
	min = find_min(stack);
	if ((stack[0] == min && stack[2] == max) ||
		(stack[2] == min && stack[1] == max) || stack[0] == max)
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

int	size_small_algorithm(int *stack_A, int *stack_B)
{
	int	min;
	int position_A;
	int position_B;
	int ra;
	int rb;
	int ops;

	ops = 0;
	while (stack_len(stack_A) != 3)
	{
		min = find_min(stack_A);
		position_A = CALCULATE_find_current_position(min, stack_A);
		ra = CALCULATE_rotation_or_reverse(position_A, stack_A);
		position_B = find_gap(min, stack_B);
		rb = CALCULATE_rotation_or_reverse(position_B, stack_B);
		ops += rotate(ra, rb, stack_A, stack_B);
		ops += apply_push(stack_B, stack_A);
		write(1, "pa\n", 3);
	}
	ops += size_mini_algorithm(stack_len(stack_A), stack_A);
	ops += move_all_to_other(stack_A, stack_B);
	return (ops);
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
	if(is_sorted(stack_A))
		return (0);
	if (amount > 15)
		return (size_big_algorithm(chunck_size, amount, stack_A, stack_B));
	else if (amount > 3)
		return (size_small_algorithm(stack_A, stack_B));
	else if (amount > 0)
		return (size_mini_algorithm(amount, stack_A));
	return (-1);
}

// int main()
// {
// 	int i = 0;
// 	int *stackA = malloc(1000 * sizeof(int));

//     if (!stackA) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }
// 	// int values[] = {1, 4, 0, 2, -1};
// 	int values[] = {479, 7, 101, 278, 255, 409, 186, 289, 210, 405, 233, 192, 70, 158, 346, 368, 88, 331, 188, 399, 316, 327, 448, 221, 115, 319, 459, 436, 458, 445, 134, 422, 407, 28, 112, 111, 296, 212, 451, 126, 251, 95, 219, 196, 401, 166, 140, 370, 469, 178, 365, 97, 357, 156, 496, 353, 276, 393, 396, 151, 240, 44, 317, 47, 237, 293, 320, 100, 425, 332, 413, 315, 228, 392, 105, 9, 31, 118, 282, 238, 476, 11, 222, 1, 466, 442, 200, 37, 261, 345, 48, 286, 116, 452, 172, 427, 300, 109, 132, 107, 263, 260, 435, 245, 41, 193, 27, 421, 177, 376, 382, 14, 272, 51, 34, 69, 165, 379, 29, 490, 280, 359, 417, 239, 372, 464, 468, 330, 270, 264, 329, 489, 284, 412, 164, 477, 106, 16, 497, 120, 189, 294, 397, 67, 471, 56, 281, 301, 133, 287, 26, 122, 18, 443, 371, 181, 481, 25, 35, 247, 248, 312, 313, 39, 225, 344, 17, 275, 456, 446, 349, 135, 176, 279, 364, 403, 117, 216, 386, 153, 92, 483, 131, 128, 437, 383, 334, 5, 72, 75, 406, 87, 36, 214, 55, 453, 340, 139, 395, 3, 333, 455, 465, 71, 324, 144, 269, 302, 108, 201, 351, 381, 387, 335, 215, 283, 423, 298, 292, 13, 58, 54, 174, 291, 478, 450, 229, 373, 22, 408, 297, 414, 155, 454, 227, 285, 258, 338, 343, 83, 231, 162, 253, 57, 491, 439, 197, 449, 4, 152, 147, 441, 398, 493, 63, 378, 369, 303, 339, 194, 385, 60, 43, 234, 336, 267, 262, 424, 170, 328, 38, 76, 377, 142, 218, 259, 150, 337, 274, 252, 463, 168, 185, 141, 305, 426, 84, 62, 89, 461, 171, 195, 183, 482, 318, 494, 257, 102, 46, 223, 495, 217, 473, 375, 123, 77, 350, 363, 205, 486, 68, 99, 53, 288, 323, 390, 419, 143, 265, 418, 114, 309, 30, 179, 416, 15, 23, 352, 391, 167, 173, 389, 310, 8, 492, 366, 160, 20, 207, 295, 224, 304, 59, 159, 52, 367, 314, 498, 361, 220, 308, 266, 249, 90, 198, 65, 432, 180, 299, 104, 86, 402, 355, 113, 347, 82, 242, 12, 2, 342, 163, 148, 400, 236, 232, 80, 311, 110, 33, 271, 157, 45, 430, 21, 307, 277, 358, 488, 98, 81, 124, 127, 202, 433, 404, 191, 410, 209, 485, 326, 388, 199, 190, 380, 411, 130, 119, 440, 73, 480, 243, 384, 484, 475, 428, 10, 6, 431, 66, 254, 154, 161, 250, 420, 175, 268, 182, 341, 447, 321, 241, 24, 438, 462, 129, 204, 273, 121, 61, 64, 208, 149, 474, 444, 374, 146, 145, 211, 136, 354, 103, 226, 0, 85, 362, 94, 138, 206, 91, 472, 49, 360, 42, 457, 74, 325, 256, 348, 460, 169, 50, 246, 93, 213, 32, 290, 322, 184, 187, 79, 499, 125, 470, 306, 487, 415, 40, 78, 356, 394, 19, 230, 96, 434, 203, 235, 244, 467, 429, 137, -1};
//     int num_values = sizeof(values) / sizeof(values[0]);

//     for (i = 0; i < num_values; i++)
// 	{
//         stackA[i] = values[i];
// 	}

// 	int *stackB = malloc(1000 * sizeof(int));

//     if (!stackB) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }
//     int valuesb[] = {-1};
//     num_values = sizeof(values) / sizeof(values[0]);

//     for (i = 0; i < num_values; i++)
// 	{
//         stackB[i] = valuesb[i];
// 	}

// 	i = 0;
// 	while (stackA[i] != -1)
// 		printf("%d ", stackA[i++]);
// 	printf("%d ", stackA[i]);
// 	printf("\n");
// 	i = 0;
// 	while (stackB[i] != -1)
// 		printf("%d ", stackB[i++]);
// 	printf("%d ", stackB[i]);
// 	printf("\n");
// 	printf("\n");

// 	int ops = algorithm(500, stack_len(stackA), stackA, stackB);

// 	i = 0;
// 	while (stackA[i] != -1)
// 		printf("%d ", stackA[i++]);
// 	printf("%d ", stackA[i]);
// 	printf("\n");
// 	i = 0;
// 	while (stackB[i] != -1)
// 		printf("%d ", stackB[i++]);
// 	printf("%d ", stackB[i]);
// 	printf("\n\n");
// 	printf("Operations: %d", ops);
// 	return 0;
// }

int main()
{
	int i = 0;

	int chunck_size = 550;
	while(chunck_size < 501)
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
	return 0;
}
