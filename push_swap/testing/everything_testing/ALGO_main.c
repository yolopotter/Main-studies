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

int main(int ac, char **av)
{
	int i = 0;

	int *stackB = malloc(1000 * sizeof(int));

    if (!stackB) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < 1001; i++)
	{
        stackB[i] = -1;
	}

	int *stackA = parsing(ac, av);
	if(!stackA)
	{
		printf("Error\n");
		return 0;
	}
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

	int ops = algorithm(500, stack_len(stackA), stackA, stackB);

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
// SINGLE ARRAY TEST

// int main()
// {
// 	int i = 0;
// 	int *stackA = malloc(1000 * sizeof(int));

//     if (!stackA) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }
// 	// int values[] = {1, 4, 0, 2, -1};
// 	int values[] = {26, 358, 290, 438, 477, 496, 185, 483, 105, 361, 238, 444, 79, 423, 96, 365, 178, 106, 356, 396, 180, 472, 305, 2, 445, 334, 391, 119, 368, 67, 115, 439, 300, 226, 62, 277, 41, 133, 473, 314, 470, 222, 263, 1, 236, 28, 337, 269, 36, 242, 219, 170, 315, 455, 88, 221, 135, 450, 233, 118, 43, 429, 58, 140, 388, 160, 172, 433, 371, 71, 229, 497, 54, 476, 145, 252, 150, 49, 461, 149, 39, 324, 386, 136, 467, 22, 114, 313, 394, 228, 250, 259, 30, 25, 407, 460, 247, 355, 490, 488, 349, 125, 211, 199, 482, 98, 84, 286, 310, 6, 34, 46, 10, 402, 267, 272, 103, 53, 216, 376, 166, 89, 303, 360, 329, 73, 323, 184, 82, 428, 215, 5, 176, 122, 333, 436, 240, 275, 419, 302, 16, 417, 459, 297, 111, 345, 81, 266, 425, 20, 304, 251, 447, 65, 155, 265, 468, 187, 403, 485, 462, 352, 202, 380, 59, 398, 282, 97, 284, 332, 171, 21, 141, 326, 224, 9, 231, 321, 241, 293, 218, 420, 159, 442, 12, 201, 481, 181, 186, 273, 61, 40, 392, 395, 151, 189, 328, 193, 100, 147, 449, 469, 209, 192, 11, 336, 153, 13, 495, 257, 137, 109, 45, 357, 262, 381, 127, 346, 435, 168, 162, 379, 47, 287, 24, 325, 144, 270, 292, 430, 486, 384, 164, 478, 370, 471, 431, 279, 77, 458, 102, 347, 112, 94, 206, 246, 190, 208, 491, 108, 15, 280, 301, 421, 405, 78, 44, 389, 487, 225, 124, 214, 23, 499, 194, 348, 183, 338, 479, 177, 101, 197, 414, 344, 50, 217, 51, 437, 341, 207, 237, 434, 276, 56, 309, 55, 243, 375, 339, 382, 291, 234, 69, 484, 70, 230, 4, 130, 68, 129, 443, 63, 416, 494, 426, 354, 289, 227, 274, 191, 400, 161, 320, 446, 244, 139, 232, 308, 174, 64, 92, 294, 412, 87, 475, 142, 239, 17, 196, 322, 179, 128, 173, 91, 107, 203, 285, 157, 281, 343, 378, 138, 261, 66, 90, 154, 104, 93, 167, 316, 200, 205, 372, 466, 278, 366, 27, 152, 0, 452, 52, 60, 364, 335, 377, 363, 295, 307, 271, 492, 258, 210, 342, 120, 453, 367, 223, 175, 427, 8, 401, 86, 143, 385, 198, 31, 165, 415, 464, 463, 432, 331, 33, 74, 131, 319, 188, 249, 424, 146, 169, 454, 393, 480, 14, 264, 260, 410, 99, 75, 283, 317, 298, 359, 80, 29, 397, 32, 121, 255, 387, 474, 256, 158, 399, 95, 312, 373, 413, 390, 42, 35, 451, 220, 156, 406, 465, 132, 245, 116, 418, 38, 408, 299, 422, 254, 57, 350, 340, 327, 411, 213, 253, 353, 235, 123, 383, 457, 374, 110, 351, 489, 248, 369, 409, 330, 306, 311, 362, 19, 318, 126, 441, 195, 404, 296, 48, 448, 498, 456, 72, 148, 288, 493, 3, 113, 440, 18, 117, 163, 7, 212, 182, 134, 85, 76, 204, 37, 268, 83, -1};
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

// TEST FOR MULTIPLE CHUNCK SIZES

// int main()
// {
// 	int i = 0;

// 	int chunck_size = 240;
// 	while(chunck_size < 260)
// 	{
// 		int *stackA = malloc(1000 * sizeof(int));
// 		int values[] = {459, 106, 337, 198, 68, 376, 204, 184, 137, 272, 322, 344, 299, 426, 134, 33, 239, 35, 499, 61, 413, 414, 291, 225, 46, 496, 62, 161, 183, 49, 245, 353, 164, 236, 256, 6, 187, 229, 347, 162, 462, 182, 94, 479, 149, 440, 345, 20, 247, 447, 215, 116, 264, 249, 483, 193, 296, 455, 292, 16, 112, 315, 382, 278, 492, 423, 78, 306, 169, 324, 234, 221, 386, 404, 213, 486, 41, 476, 67, 117, 58, 86, 284, 75, 403, 212, 277, 108, 430, 166, 339, 14, 262, 13, 261, 197, 317, 246, 400, 352, 233, 412, 484, 285, 209, 10, 385, 196, 224, 457, 210, 121, 168, 144, 355, 495, 335, 309, 238, 331, 318, 195, 8, 281, 53, 276, 305, 76, 103, 374, 122, 83, 2, 329, 186, 231, 438, 191, 87, 465, 409, 131, 171, 109, 57, 361, 489, 40, 288, 177, 17, 308, 445, 378, 321, 268, 410, 22, 15, 235, 336, 202, 311, 443, 302, 289, 280, 74, 402, 211, 18, 275, 254, 138, 19, 147, 425, 478, 300, 482, 170, 96, 113, 380, 0, 466, 82, 158, 25, 456, 454, 42, 104, 139, 418, 307, 232, 90, 206, 485, 357, 207, 295, 24, 434, 85, 45, 222, 200, 303, 341, 100, 266, 154, 143, 152, 226, 342, 363, 237, 477, 314, 348, 38, 398, 467, 52, 111, 313, 43, 32, 30, 388, 406, 44, 155, 218, 428, 253, 330, 384, 77, 216, 230, 79, 463, 470, 175, 180, 189, 390, 415, 279, 145, 326, 343, 133, 497, 263, 176, 70, 119, 50, 360, 286, 36, 283, 498, 255, 115, 88, 419, 359, 23, 460, 251, 217, 270, 480, 448, 297, 127, 346, 444, 411, 73, 265, 181, 422, 367, 474, 242, 165, 219, 47, 118, 95, 51, 151, 312, 89, 55, 493, 350, 146, 163, 99, 93, 351, 223, 481, 56, 1, 435, 48, 451, 60, 271, 332, 141, 66, 407, 110, 244, 26, 173, 107, 84, 373, 27, 334, 3, 4, 157, 487, 432, 29, 458, 31, 333, 475, 439, 11, 240, 220, 208, 399, 65, 267, 178, 174, 258, 179, 436, 128, 424, 396, 248, 153, 408, 160, 366, 12, 372, 130, 132, 136, 471, 320, 369, 80, 377, 64, 273, 126, 114, 159, 437, 449, 294, 446, 59, 429, 129, 287, 241, 391, 21, 7, 243, 461, 340, 379, 405, 365, 441, 214, 92, 156, 325, 316, 433, 370, 327, 185, 371, 323, 102, 362, 105, 120, 319, 469, 34, 472, 491, 201, 356, 338, 368, 397, 274, 142, 395, 442, 494, 417, 192, 290, 190, 203, 135, 393, 375, 205, 392, 257, 282, 490, 69, 252, 387, 39, 364, 37, 63, 28, 101, 301, 260, 431, 464, 420, 358, 188, 488, 452, 227, 5, 228, 140, 125, 148, 293, 91, 81, 72, 194, 427, 394, 98, 259, 468, 123, 354, 167, 172, 401, 199, 54, 124, 150, 450, 416, 381, 269, 298, 473, 71, 383, 421, 328, 97, 349, 310, 453, 9, 389, 304, 250, -1};
// 		int num_values = sizeof(values) / sizeof(values[0]);

// 		for (i = 0; i < num_values; i++)
// 		{
// 			stackA[i] = values[i];
// 		}

// 		int *stackB = malloc(1000 * sizeof(int));

// 		if (!stackB) {
// 			printf("Memory allocation failed\n");
// 			return 1;
// 		}
// 		int valuesb[] = {-1};
// 		num_values = sizeof(values) / sizeof(values[0]);

// 		for (i = 0; i < num_values; i++)
// 		{
// 			stackB[i] = valuesb[i];
// 		}
// 		int ops = algorithm(chunck_size, stack_len(stackA), stackA, stackB);
// 		printf("chunck size %i, Operations: %d\n", chunck_size, ops);
// 		free(stackA);
// 		free(stackB);
// 		chunck_size++;
// 	}
// 	return 0;
// }
