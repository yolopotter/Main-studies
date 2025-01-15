/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:04:39 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 10:43:06 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		write(1, "pb\n", 3);
	}
	ops += size_mini_algorithm(stack_len(stack_A), stack_A);
	ops += move_all_to_other(stack_A, stack_B);
	return (ops);
}
