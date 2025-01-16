/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:55 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 20:40:03 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_final_pos(int *stack_a)
{
	int	nb;
	int	position;
	int	ra;

	nb = find_min(stack_a);
	position = calc_find_current_position(nb, stack_a);
	ra = calc_rotation_or_reverse(position, stack_a);
	while (ra != 0)
	{
		if (ra < 0)
		{
			apply_reverse_rotation(stack_a);
			ra++;
			ft_putstr_fd("rra\n", 1);
		}
		else
		{
			apply_rotation(stack_a);
			ra--;
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	move_all_to_other(int amount, int *stack_b, int *stack_a) // merge this somehow with the other one
{
	int		j;
	t_calc	calc;

	j = 0;
	while (j < amount)
	{
		calc.current_nb = calc_find_cheapest_nb(amount - 1, stack_b, stack_a, B_TO_A);
		calc.position = calc_find_current_position(calc.current_nb, stack_b);
		calc.rb = calc_rotation_or_reverse(calc.position, stack_b);
		calc.position = find_gap(calc.current_nb, stack_a, B_TO_A);
		calc.ra = calc_rotation_or_reverse(calc.position, stack_a);
		rotate(calc.ra, calc.rb, stack_a, stack_b);
		apply_push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
		j++;
	}
}

int	size_big_algorithm(int amount, int *stack_a, int *stack_b)
{
	int		j;
	t_calc	calc;

	j = 0;
	while (j < amount - 3)
	{
		calc.current_nb = calc_find_cheapest_nb(amount - 4, stack_a, stack_b, A_TO_B);
		calc.position = calc_find_current_position(calc.current_nb, stack_a);
		calc.ra = calc_rotation_or_reverse(calc.position, stack_a);
		calc.position = find_gap(calc.current_nb, stack_b, A_TO_B);
		calc.rb = calc_rotation_or_reverse(calc.position, stack_b);
		rotate(calc.ra, calc.rb, stack_a, stack_b);
		apply_push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
		j++;
	}
	size_mini_algorithm(3, stack_a);
	move_all_to_other(stack_len(stack_b), stack_b, stack_a);
	rotate_to_final_pos(stack_a);
	return (1);
}
