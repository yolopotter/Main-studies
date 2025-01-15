/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:55 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 15:17:58 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_big_algorithm(int amount, int *stack_A, int *stack_B)
{
	int	position;
	int	current_nb;
	int	ra;
	int	rb;
	int	j;

	j = 0;
	while (j < amount)
	{
		current_nb = CALCULATE_find_cheapest_nb(amount - 1, stack_A, stack_B);
		position = CALCULATE_find_current_position(current_nb, stack_A);
		ra = CALCULATE_rotation_or_reverse(position, stack_A);
		position = find_gap(current_nb, stack_B);
		rb = CALCULATE_rotation_or_reverse(position, stack_B);
		rotate(ra, rb, stack_A, stack_B);
		apply_push(stack_B, stack_A);
		write(1, "pb\n", 3);
		j++;
	}
	move_all_to_other(stack_A, stack_B);
	return (1);
}
