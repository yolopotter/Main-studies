/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:55 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 16:41:46 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_all_to_other(int *stack_a, int *stack_b)
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

int	size_big_algorithm(int amount, int *stack_a, int *stack_b)
{
	int		j;
	t_calc	calc;

	j = 0;
	while (j < amount)
	{
		calc.current_nb = calc_find_cheapest_nb(amount - 1, stack_a, stack_b);
		calc.position = calc_find_current_position(calc.current_nb, stack_a);
		calc.ra = calc_rotation_or_reverse(calc.position, stack_a);
		calc.position = find_gap(calc.current_nb, stack_b);
		calc.rb = calc_rotation_or_reverse(calc.position, stack_b);
		rotate(calc.ra, calc.rb, stack_a, stack_b);
		apply_push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
		j++;
	}
	// size_mini_under_3(3, stack_a);
	move_all_to_other(stack_a, stack_b);
	return (1);
}
