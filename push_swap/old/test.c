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

static int	find_max(int *stack_B)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while(stack_B[i] != -1)
	{
		if (stack_B[i] > max)
			max = stack_B[i];
		i++;
	}
	return (max);
}

int	find_gap(int nb, int *stack_B)
{
	int	i;
	int	max;

	i = 0;
	max = find_max(stack_B);
	while(stack_B[i] != -1)
	{
		if (nb > max)
		{
			i = 0;
			while (stack_B[i] != -1)
			{
				if(stack_B[i] == max)
					return (i);
				i++;
			}
		}
		if (nb < stack_B[i] && nb < stack_B[i + 1])
			return (i);
		if (nb > stack_B[i] && nb < stack_B[i + 1])
			return (i);
		i++;
	}
	return (i);
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

int	algorithm(int amount, int *stack_A, int *stack_B)
{
	int	ops;
	int i = 0;
	int j = 0;
	ops = 0;

	j = stack_len(stack_A);
	while(j > 0)
	{
		i = stack_len(stack_A);
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
		ops++;
		// printf("pa\n");
		j--;
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
    int values[] = {365, 172, 398, 432, 251, 285, 460, 491, 159, 401, 82, 68, 421, 4, 356, 203, 359, 400, 231, 183, 13, 200, 32, 328, 430, 424, 487, 233, 453, 352, 15, 134, 107, 143, 380, 85, 106, 126, 145, 24, 218, 264, 483, 404, 9, 122, 29, 148, 88, 27, 433, 31, 336, 499, 324, 7, 110, 350, 498, 366, 419, 492, 458, 81, 35, 289, 422, 467, 314, 307, 30, 434, 118, 154, 273, 397, 465, 104, 353, 179, 105, 388, 164, 207, 72, 339, 22, 93, 57, 450, 468, 176, 20, 227, 416, 70, 244, 21, 201, 274, 112, 443, 303, 129, 195, 286, 186, 361, 437, 384, 17, 243, 452, 77, 86, 240, 379, 34, 99, 51, 275, 36, 225, 456, 247, 202, 219, 69, 190, 382, 493, 348, 268, 175, 411, 389, 167, 43, 213, 470, 340, 451, 163, 446, 494, 442, 427, 329, 322, 315, 59, 265, 136, 250, 194, 189, 8, 280, 306, 133, 355, 318, 1, 181, 362, 180, 234, 103, 461, 137, 114, 44, 215, 347, 135, 162, 248, 436, 386, 169, 271, 182, 335, 448, 165, 155, 120, 300, 276, 222, 469, 220, 212, 390, 117, 413, 269, 41, 224, 308, 256, 496, 64, 149, 10, 301, 229, 128, 84, 482, 290, 94, 101, 471, 459, 146, 96, 196, 63, 100, 316, 210, 245, 345, 258, 270, 293, 18, 193, 119, 108, 327, 317, 131, 230, 330, 14, 351, 497, 344, 221, 239, 158, 249, 272, 232, 480, 425, 466, 2, 299, 3, 140, 368, 302, 343, 115, 197, 42, 371, 157, 253, 292, 130, 475, 95, 488, 208, 402, 349, 485, 438, 377, 313, 296, 408, 259, 392, 396, 479, 141, 92, 287, 478, 61, 341, 46, 89, 464, 237, 477, 52, 435, 417, 295, 369, 294, 441, 373, 455, 90, 49, 429, 87, 11, 79, 495, 37, 168, 283, 374, 378, 281, 439, 298, 445, 75, 260, 191, 171, 255, 383, 428, 342, 142, 150, 360, 263, 449, 97, 66, 357, 241, 60, 45, 58, 323, 177, 385, 19, 187, 214, 242, 367, 91, 297, 173, 178, 405, 489, 166, 418, 113, 144, 6, 414, 254, 23, 78, 454, 151, 174, 235, 55, 423, 16, 73, 116, 412, 490, 447, 391, 0, 473, 124, 198, 403, 426, 80, 372, 364, 399, 39, 319, 331, 395, 304, 236, 338, 325, 38, 282, 47, 474, 420, 358, 309, 127, 305, 415, 387, 223, 354, 40, 481, 217, 407, 25, 76, 156, 28, 261, 311, 67, 484, 370, 431, 363, 50, 288, 257, 56, 326, 440, 312, 266, 267, 337, 376, 139, 111, 216, 153, 381, 204, 205, 83, 226, 74, 462, 291, 252, 147, 5, 53, 199, 332, 109, 123, 188, 184, 185, 54, 393, 211, 444, 125, 278, 228, 238, 170, 333, 132, 48, 410, 209, 284, 310, 33, 121, 206, 346, 62, 457, 71, 160, 486, 161, 375, 246, 321, 320, 262, 152, 138, 472, 409, 98, 476, 279, 26, 277, 102, 65, 12, 394, 192, 463, 334, 406, -1};
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
