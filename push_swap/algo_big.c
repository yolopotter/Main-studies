/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:55 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 22:10:29 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_all_to_other(int *stack_A, int *stack_B)
{
	int len;
	int	min;

	len = 0;
	min = find_min(stack_B);
	len = stack_len(stack_B);
	while (stack_B[0] != min)
	{
		apply_rotation(stack_B);
		write(1, "rb\n", 3);
	}
	while (len > 0)
	{
		apply_push(stack_A, stack_B);
		write(1, "pa\n", 3);
		len--;
	}
}

int	size_big_algorithm(int amount, int *stack_A, int *stack_B)
{
	int	j;
	t_calc calc;

	j = 0;
	while (j < amount)
	{
		calc.current_nb = CALCULATE_find_cheapest_nb(amount - 1, stack_A, stack_B);
		calc.position = CALCULATE_find_current_position(calc.current_nb, stack_A);
		calc.ra = CALCULATE_rotation_or_reverse(calc.position, stack_A);
		calc.position = find_gap(calc.current_nb, stack_B);
		calc.rb = CALCULATE_rotation_or_reverse(calc.position, stack_B);
		rotate(calc.ra, calc.rb, stack_A, stack_B);
		apply_push(stack_B, stack_A);
		write(1, "pb\n", 3);
		j++;
	}
	// size_mini_under_3(3, stack_A);
	move_all_to_other(stack_A, stack_B);
	return (1);
}
