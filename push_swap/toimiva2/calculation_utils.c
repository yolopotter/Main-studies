/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:33:09 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 12:13:35 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_find_current_position(int current, int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i] != -1)
	{
		if (stack_a[i] == current)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
