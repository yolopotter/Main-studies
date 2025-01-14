/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:55 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 15:10:10 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_big_algorithm(int amount, int *stack_A, int *stack_B)
{
	int	ops;			//amount of operations
	int	position; //position	i;
	int	current_nb;
	int	position_A;
	int	position_B;
	int	ra;
	int	rb;
	int	j;

	ops = 0;
	j = 0;
	while (j < amount)
	{
		position = CALCULATE_find_cheapest_nb(0, amount - 1, stack_A, stack_B);
		current_nb = stack_A[position];
		position_A = CALCULATE_find_current_position(current_nb, stack_A);
		ra = CALCULATE_rotation_or_reverse(position_A, stack_A);
		position_B = find_gap(current_nb, stack_B);
		rb = CALCULATE_rotation_or_reverse(position_B, stack_B);
		ops += rotate(ra, rb, stack_A, stack_B);
		apply_push(stack_B, stack_A);
		ops++;
		// write(1, "pa\n", 3);
		j++;
	}
	ops += move_all_to_other(stack_A, stack_B);
	return (ops);
}
