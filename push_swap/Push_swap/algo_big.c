/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:09:55 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 13:18:20 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_final_pos(int *stack_a)
{
	int	nb;
	int	position;
	int	ra;

	nb = find_min(stack_a);
	position = cal_find_current_position(nb, stack_a);
	ra = cal_rotation_or_reverse(position, stack_a);
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

void	move_all_to_other(int len, int *stack_b, int *stack_a)
{
	int		j;
	t_calc	cal;

	j = 0;
	while (j < len)
	{
		cal.curr_nb = cal_find_cheapest_nb(len - 1, stack_b, stack_a, B_TO_A);
		cal.position = cal_find_current_position(cal.curr_nb, stack_b);
		cal.rb = cal_rotation_or_reverse(cal.position, stack_b);
		cal.position = find_gap(cal.curr_nb, stack_a, B_TO_A);
		cal.ra = cal_rotation_or_reverse(cal.position, stack_a);
		rotate(cal.ra, cal.rb, stack_a, stack_b);
		apply_push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
		j++;
	}
}

int	size_big_algorithm(int len, int *stack_a, int *stack_b)
{
	int		j;
	t_calc	cal;

	j = 0;
	while (stack_len(stack_a) != 3)
	{
		cal.curr_nb = cal_find_cheapest_nb(len - 4, stack_a, stack_b, A_TO_B);
		cal.position = cal_find_current_position(cal.curr_nb, stack_a);
		cal.ra = cal_rotation_or_reverse(cal.position, stack_a);
		cal.position = find_gap(cal.curr_nb, stack_b, A_TO_B);
		cal.rb = cal_rotation_or_reverse(cal.position, stack_b);
		rotate(cal.ra, cal.rb, stack_a, stack_b);
		apply_push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
		j++;
	}
	size_mini_algorithm(3, stack_a);
	move_all_to_other(stack_len(stack_b), stack_b, stack_a);
	rotate_to_final_pos(stack_a);
	return (1);
}
