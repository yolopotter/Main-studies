/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:51:54 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 21:07:40 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(int *stack)
{
	int	len;

	len = 0;
	while (stack[len] != -1)
		len++;
	return (len);
}

int	find_max(int *stack)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (stack[i] != -1)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	find_min(int *stack)
{
	int	i;
	int	min;

	i = 0;
	if (stack_len(stack) == 0)
		return (0);
	min = stack[i];
	while (stack[i] != -1)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	is_sorted(int *stack)
{
	int	i;

	i = 1;
	while (stack[i] != -1)
	{
		if (stack[i] > stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}
