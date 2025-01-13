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

int	algorithm(int chunck_size, int amount, int *stack_A, int *stack_B)
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

int main()
{
	int i = 0;
	int *stackA = malloc(1000 * sizeof(int));

    if (!stackA) {
        printf("Memory allocation failed\n");
        return 1;
    }
	// int values[] = {16, 2, 4, 0, 15, 9, 12, 1, 3, 10, 6, 8, 14, 17, 7, 13, 5, 11, -1};
	// int values[] = {194, 27, 188, 132, 442, 432, 57, 82, 54, 417, 105, 444, 156, 322, 469, 219, 368, 275, 324, 189, 126, 217, 87, 5, 173, 28, 394, 68, 213, 445, 102, 471, 176, 210, 373, 240, 382, 472, 377, 181, 485, 153, 455, 231, 302, 157, 118, 360, 174, 277, 155, 30, 374, 356, 203, 318, 14, 438, 187, 141, 160, 398, 248, 330, 376, 59, 456, 147, 437, 258, 264, 367, 473, 225, 80, 139, 108, 339, 232, 280, 278, 242, 393, 49, 185, 361, 300, 353, 410, 265, 193, 355, 75, 218, 347, 37, 7, 365, 305, 462, 66, 9, 175, 409, 224, 349, 321, 158, 72, 387, 200, 488, 319, 492, 370, 93, 212, 427, 109, 420, 497, 208, 424, 143, 64, 466, 422, 206, 348, 487, 4, 494, 15, 183, 448, 333, 234, 196, 101, 246, 358, 392, 429, 53, 463, 452, 178, 36, 419, 294, 214, 235, 384, 202, 35, 256, 268, 447, 0, 154, 145, 317, 297, 346, 309, 45, 359, 252, 281, 195, 220, 121, 421, 273, 65, 19, 85, 81, 380, 334, 325, 18, 99, 69, 415, 291, 148, 404, 350, 136, 8, 21, 254, 340, 407, 270, 107, 222, 400, 341, 84, 149, 61, 464, 286, 489, 363, 128, 304, 425, 441, 227, 262, 408, 287, 211, 279, 381, 78, 92, 389, 320, 167, 1, 483, 63, 496, 236, 95, 323, 16, 484, 241, 117, 342, 386, 391, 124, 162, 423, 186, 308, 165, 314, 22, 47, 315, 267, 228, 91, 459, 375, 83, 336, 476, 388, 433, 191, 131, 60, 23, 260, 144, 43, 164, 192, 152, 450, 379, 197, 307, 312, 230, 190, 301, 216, 431, 106, 79, 10, 44, 111, 11, 385, 481, 55, 58, 70, 244, 52, 454, 51, 402, 428, 168, 138, 298, 29, 486, 261, 96, 299, 135, 161, 271, 125, 335, 477, 13, 146, 285, 169, 50, 48, 412, 449, 3, 110, 289, 42, 89, 453, 390, 33, 133, 434, 179, 470, 34, 411, 430, 436, 282, 413, 151, 113, 498, 223, 293, 150, 403, 97, 76, 198, 239, 460, 243, 238, 458, 490, 383, 399, 499, 207, 352, 67, 418, 245, 98, 378, 251, 73, 170, 237, 204, 180, 257, 405, 451, 253, 395, 326, 24, 478, 364, 461, 38, 416, 221, 495, 205, 137, 414, 249, 311, 104, 120, 74, 482, 226, 396, 288, 327, 351, 331, 344, 2, 32, 129, 337, 468, 369, 479, 142, 303, 25, 266, 259, 233, 100, 491, 426, 465, 439, 435, 12, 46, 474, 177, 295, 172, 296, 26, 440, 272, 338, 112, 116, 329, 313, 306, 255, 371, 171, 103, 345, 446, 276, 250, 62, 397, 290, 401, 41, 123, 114, 480, 215, 493, 343, 310, 316, 6, 247, 332, 88, 163, 269, 357, 127, 166, 40, 366, 130, 199, 475, 328, 354, 20, 140, 115, 457, 159, 283, 229, 122, 372, 263, 209, 284, 184, 86, 362, 31, 90, 467, 182, 77, 71, 406, 119, 443, 274, 94, 292, 17, 134, 201, 56, 39, -1};
    // int num_values = sizeof(values) / sizeof(values[0]);

    // for (i = 0; i < num_values; i++)
	// {
    //     stackA[i] = values[i];
	// }

	// int *stackB = malloc(1000 * sizeof(int));

    // if (!stackB) {
    //     printf("Memory allocation failed\n");
    //     return 1;
    // }
    // int valuesb[] = {-1};
    // num_values = sizeof(values) / sizeof(values[0]);

    // for (i = 0; i < num_values; i++)
	// {
    //     stackB[i] = valuesb[i];
	// }

	// i = 0;
	// while (stackA[i] != -1)
	// 	printf("%d ", stackA[i++]);
	// printf("%d ", stackA[i]);
	// printf("\n");
	// i = 0;
	// while (stackB[i] != -1)
	// 	printf("%d ", stackB[i++]);
	// printf("%d ", stackB[i]);
	// printf("\n");
	// printf("\n");

	int chunck_size = 1;
	while(chunck_size < 101)
	{
		int *stackA = malloc(1000 * sizeof(int));
		int values[] = {86, 40, 91, 8, 21, 59, 90, 35, 46, 32, 3, 19, 5, 81, 33, 89, 77, 48, 28, 80, 44, 65, 73, 70, 45, 22, 85, 14, 94, 71, 60, 6, 74, 36, 17, 58, 82, 76, 99, 24, 42, 69, 31, 68, 16, 41, 96, 78, 84, 66, 98, 97, 47, 56, 88, 93, 20, 49, 63, 38, 55, 92, 72, 27, 12, 67, 7, 13, 4, 52, 0, 18, 95, 29, 23, 9, 37, 64, 10, 30, 34, 11, 43, 39, 57, 15, 75, 87, 54, 50, 25, 83, 62, 2, 61, 26, 79, 51, 53, 1, -1};
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
