/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ALGO_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:14 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 16:12:56 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		write(1, "rb\n", 3);
		ops++;
	}
	while (len > 0)
	{
		apply_push(dst, src);
		write(1, "pb\n", 3);
		ops++;
		len--;
	}
	return (ops);
}

int	algorithm(int amount, int *stack_A, int *stack_B)
{
	if(is_sorted(stack_A))
		return (0);
	if (amount > 15)
		return (size_big_algorithm(amount, stack_A, stack_B));
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
	algorithm(stack_len(stackA), stackA, stackB);
	// int ops = algorithm(stack_len(stackA), stackA, stackB);

	// printf("\n");
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

	// printf("is sorted: %i\n", is_sorted(stackA));

	// printf("\n");
	// printf("Operations: %d", ops);
	return 0;
}

//-------------------------------------------------------------------------------------------------------------
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

// 	int ops = algorithm(stack_len(stackA), stackA, stackB);

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
// 	printf("is sorted: %i\n", is_sorted(stackA));
// 	printf("Operations: %d", ops);
// 	return 0;
// }
