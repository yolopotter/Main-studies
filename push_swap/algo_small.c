/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:04:39 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 20:40:19 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_all_b_to_a(int *stack_a, int *stack_b)
{
	int	len;
	int	min;

	len = 0;
	min = find_min(stack_b);
	len = stack_len(stack_b);
	while (stack_b[0] != min)
	{
		apply_rotation(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	while (len > 0)
	{
		apply_push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
		len--;
	}
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
			ft_putstr_fd("sa\n", 1);
			return (1);
		}
		return (0);
	}
}

int	size_mini_algorithm(int amount, int *stack)
{
	int	max;
	int	min;

	if (is_sorted(stack))
		return (0);
	if (amount < 3)
		return (size_mini_under_3(amount, stack));
	max = find_max(stack);
	min = find_min(stack);
	if ((stack[0] == min && stack[2] == max) || \
		(stack[2] == min && stack[1] == max) || stack[0] == max)
	{
		apply_swap(stack);
		ft_putstr_fd("sa\n", 1);
	}
	while (stack[0] != max)
	{
		apply_rotation(stack);
		ft_putstr_fd("ra\n", 1);
	}
	return (1);
}

int	size_small_algorithm(int *stack_a, int *stack_b)
{
	int	min;
	int	position;
	int	ra;
	int	rb;

	while (stack_len(stack_a) != 3)
	{
		min = find_min(stack_a);
		position = calc_find_current_position(min, stack_a);
		ra = calc_rotation_or_reverse(position, stack_a);
		position = find_gap(min, stack_b, A_TO_B);
		rb = calc_rotation_or_reverse(position, stack_b);
		rotate(ra, rb, stack_a, stack_b);
		apply_push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
	}
	size_mini_algorithm(stack_len(stack_a), stack_a);
	move_all_b_to_a(stack_a, stack_b);
	return (1);
}
