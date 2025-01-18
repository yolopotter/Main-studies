/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:04:39 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 13:33:01 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_mini_under_3(int len, int *stack)
{
	if (len <= 0)
		return (-1);
	else if (len == 1)
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

int	size_mini_algorithm(int len, int *stack)
{
	int	max;
	int	min;

	if (is_sorted(stack))
		return (0);
	if (len < 3)
		return (size_mini_under_3(len, stack));
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
