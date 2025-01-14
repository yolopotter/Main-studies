#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))


int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
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
			rotations++; //r
		}
	}
	else
	{
		while (pos >= 0)
		{
			pos--;
			rotations--; //rr
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
	printf("cheapest %i\n", cheapest);
	return (cheapest_position);
}

int main()
{
	int arr_A[] = {59, 43, 41, 36, 39, 35, 54, 48, 55, 42, 40, 44, 37, 31, 27, 34, 26, 46, 52, 25, 58, 32, 47, 49, 56, 53, 50, 45, 51, 57, 38, -1};
	int arr_B[] = {30, 33, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 28, 29, -1};
	int c_min = 20;
	int c_max = 35;
	int pos = CALCULATE_find_cheapest_nb(c_min, c_max, arr_A, arr_B);
	printf("cheapest pos: %i\n", pos);
	printf("cheapest num: %i\n", arr_A[pos]);
}
