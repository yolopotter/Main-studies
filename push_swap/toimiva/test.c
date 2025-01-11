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
	int j = stack_len(stack_A) - i - 1;
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

void	apply_rotation_or_reverse(int pos, int *stack, int *ops)
{
	if ((pos >= stack_len(stack) / 2))
	{
		while ((stack_len(stack) - (pos + 1)) > 0)
		{
			apply_rotation(stack);
			(*ops)++;
			// printf("rr\n");
			pos++;
		}
	}
	else
	{
		while (pos >= 0)
		{
			apply_reverse_rotation(stack);
			(*ops)++;
			// printf("rr\n");
			pos--;
		}
	}
}

int	rotate_B(int nb, int *stack_B)
{
	int	position; //position reps what is position that we want to be at top to receive a number
	int	ops;

	position = 0;
	ops = 0;
	position = find_gap(nb, stack_B);
	apply_rotation_or_reverse(position, stack_B, &ops);
	return (ops);
}

// int	CALCULATE_find_current_position(int current, int *stack_A)
// {
// 	int i;

// 	i = 0;
// 	while (stack_A[i] != current)
// 		i++;
// 	return (i - 1);
// }

// int	CALCULATE_rotation_or_reverse(int pos, int *stack, int *ops)
// {
// 	if ((pos >= stack_len(stack) / 2))
// 	{
// 		while ((stack_len(stack) - (pos + 1)) > 0)
// 		{
// 			//r
// 			(*ops)++;
// 			pos++;
// 		}
// 	}
// 	else
// 	{
// 		while (pos >= 0)
// 		{
// 			//rr
// 			(*ops)++;
// 			pos--;
// 		}
// 	}
// }

// int	CALCULATE_find_cheapest_nb(int c_min, int c_max, int *stack_A, int *stack_B) //just built, needs alot of testing
// {
// 	int	i;
// 	int	current_nb;
// 	int	position;
// 	int	ops;
// 	int	ra;
// 	int	rb;
// 	int	price;
// 	int	delta;

// 	i = 0;
// 	while (i < c_max - c_min + 1) //amount of loops is amount of numbers in range min to max.
// 	{
// 		current_nb = c_min + i;
// 		position = CALCULATE_find_current_position(current_nb, stack_A);
// 		ra = CALCULATE_rotation_or_reverse(position, stack_A, &ops);
// 		position = find_gap(current_nb, stack_B);
// 		rb = CALCULATE_rotation_or_reverse(position, stack_B, &ops);
// 		delta = ra - rb;
// 		price = delta + min(abs(ra), abs(rb));
// 		i++;
// 	}
// }

int	algorithm(int amount, int *stack_A, int *stack_B)
{
	int	chunck_size;
	int	ops;			//amount of operations
	int	current_max;
	int	current_min;
	int position = 0; //position represents what is position that we want to be at top to push
	int j = 0;
	current_max = 0;
	current_min = 0;
	ops = 0;

	// chunck_size = stack_len(stack_A) / 17;
	chunck_size = 40; //chunk size around 40 for 500 numbers is optimal.
	current_max = chunck_size - 1;
	current_min = current_max - (chunck_size - 1);
	while (current_min < amount)
	{
		if (current_max > amount - 1)
			current_max = amount - 1;
		j = current_max - current_min + 1;
		while(j > 0)
		{
			// printf("i %i\n", position);
			// position = find_cheapest_nb(current_min, current_max, stack_A, stack_B);
			position = find_closest(current_min, current_max, stack_A);
			// printf("position %i\n", position);
			apply_rotation_or_reverse(position, stack_A, &ops);
			ops += rotate_B(stack_A[stack_len(stack_A) - 1], stack_B);
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
	int values[] = {466, 145, 74, 282, 55, 314, 444, 268, 230, 335, 269, 173, 410, 194, 270, 120, 371, 481, 304, 138, 112, 391, 144, 109, 137, 213, 141, 353, 255, 358, 450, 188, 413, 18, 174, 309, 330, 387, 407, 431, 131, 455, 264, 223, 323, 96, 381, 39, 456, 418, 262, 22, 295, 184, 250, 53, 164, 369, 416, 237, 415, 130, 183, 61, 70, 198, 256, 119, 233, 33, 424, 321, 2, 94, 27, 307, 265, 8, 441, 62, 491, 44, 228, 348, 363, 272, 457, 409, 408, 207, 42, 331, 340, 300, 433, 158, 251, 218, 226, 284, 97, 126, 364, 243, 414, 7, 64, 219, 274, 182, 82, 124, 446, 393, 14, 99, 84, 467, 285, 258, 366, 162, 210, 157, 60, 315, 484, 40, 205, 79, 51, 105, 289, 442, 328, 257, 488, 448, 215, 279, 118, 81, 296, 438, 386, 134, 434, 498, 232, 181, 324, 201, 176, 227, 365, 58, 286, 185, 54, 449, 47, 229, 320, 299, 59, 191, 91, 259, 313, 15, 127, 192, 220, 166, 336, 239, 154, 75, 385, 327, 151, 372, 225, 36, 57, 355, 303, 367, 87, 378, 180, 26, 252, 133, 261, 422, 306, 271, 351, 23, 231, 435, 404, 392, 107, 9, 165, 360, 292, 93, 121, 326, 4, 89, 76, 311, 480, 66, 401, 349, 388, 236, 25, 125, 357, 177, 110, 483, 240, 160, 242, 139, 106, 395, 241, 50, 43, 163, 83, 37, 273, 116, 143, 291, 432, 123, 175, 400, 318, 148, 465, 187, 152, 6, 48, 332, 490, 440, 468, 344, 113, 122, 287, 374, 384, 28, 423, 356, 140, 208, 389, 293, 288, 266, 430, 464, 24, 108, 142, 199, 135, 439, 478, 11, 90, 338, 482, 132, 19, 20, 103, 63, 172, 477, 80, 153, 248, 495, 337, 35, 167, 298, 280, 128, 474, 334, 211, 245, 136, 278, 204, 149, 196, 38, 95, 206, 267, 263, 458, 17, 316, 308, 343, 73, 496, 370, 92, 305, 52, 428, 396, 159, 394, 129, 329, 297, 319, 100, 494, 56, 427, 322, 302, 3, 197, 77, 489, 462, 115, 419, 443, 21, 380, 247, 376, 78, 155, 301, 171, 275, 436, 86, 168, 359, 195, 497, 114, 453, 186, 212, 317, 379, 69, 294, 150, 190, 34, 463, 31, 169, 200, 276, 216, 405, 472, 339, 454, 445, 425, 170, 32, 260, 402, 161, 420, 469, 234, 460, 333, 485, 85, 461, 345, 29, 347, 222, 72, 473, 244, 221, 354, 156, 398, 189, 451, 146, 179, 254, 178, 377, 16, 470, 217, 41, 429, 30, 312, 1, 277, 65, 45, 397, 214, 382, 325, 193, 71, 417, 104, 281, 499, 452, 283, 487, 475, 350, 290, 492, 147, 390, 224, 246, 459, 98, 102, 111, 342, 67, 486, 12, 101, 88, 368, 373, 493, 447, 10, 117, 437, 421, 202, 403, 13, 203, 412, 406, 249, 352, 46, 375, 479, 471, 411, 49, 5, 341, 361, 399, 68, 0, 235, 383, 253, 209, 346, 310, 362, 238, 476, 426, -1};
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
