/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:07:26 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 21:07:42 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	find_gap_for_extremes(int *stack, t_direction dir, int min, int max)
{
	int	i;

	i = 0;
	while (stack[i] != -1)
	{
		if (dir == A_TO_B && stack[i] == max)
			return (i);
		else if (dir == B_TO_A && stack[i] == min)
			return (i);
		i++;
	}
	return (i);
}

static int	find_gap_within_range(int *stack, t_direction dir, int nb)
{
	int	i;

	i = 0;
	while (stack[i] != -1)
	{
		if (dir == A_TO_B && nb > stack[i] && nb < stack[i + 1])
			return (i);
		else if (dir == B_TO_A && nb < stack[i] && nb > stack[i + 1])
			return (i);
		i++;
	}
	return (i);
}

static int	is_outside_range(int nb, int min, int max)
{
	return (nb > max || nb < min);
}

int	find_gap(int nb, int *stack, t_direction dir)
{
	int	max;
	int	min;

	max = find_max(stack);
	min = find_min(stack);
	if (is_outside_range(nb, min, max))
		return (find_gap_for_extremes(stack, dir, min, max));
	else
		return (find_gap_within_range(stack, dir, nb));
}
