/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:56:27 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 21:06:48 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	CALCULATE_find_current_position(int current, int *stack_A)
{
	int i;

	i = 0;
	while (stack_A[i] != -1)
	{
		if (stack_A[i] == current)
			return (i);
		i++;
	}
	return (-1);
}

int	CALCULATE_rotation_or_reverse(int pos, int *stack)
{
	int rotations;

	rotations = 0;
	if ((pos >= stack_len(stack) / 2))
	{
		while ((stack_len(stack) - (pos + 1)) > 0)
		{
			pos++;
			rotations++;
		}
	}
	else
	{
		while (pos >= 0)
		{
			pos--;
			rotations--;
		}
	}
	return (rotations);
}

int	CALCULATE_find_smallest_current(int c_max, int *i, int *stack_A)
{
	while (stack_A[*i] != -1)
	{
		if (stack_A[*i] >= 0 && stack_A[*i] <= c_max)
		{
			return (stack_A[(*i)++]);
		}
		(*i)++;
	}
	return (-1);
}

int	CALCULATE_price(int ra, int rb)
{
	int delta;
	int price;

	delta = ra - rb;
	if ((ra > 0 && rb > 0) || (ra < 0 && rb < 0))
		price = ft_abs(delta) + ft_min(ft_abs(ra), ft_abs(rb));
	else
		price = ft_abs(delta);
	return (price);
}

void	CALCULATE_ra_rb(t_calc *calc, int *stack_A, int *stack_B)
{
	int position;

	position = CALCULATE_find_current_position(calc->current_nb, stack_A);
	calc->ra = CALCULATE_rotation_or_reverse(position, stack_A);
	position = find_gap(calc->current_nb, stack_B);
	calc->rb = CALCULATE_rotation_or_reverse(position, stack_B);
}

int	CALCULATE_find_cheapest_nb(int c_max, int *stack_A, int *stack_B)
{
	int	i;
	t_calc calc;

	i = 0;
	calc.cheapest = 1000000;
	while (stack_A[i] != -1)
	{
		calc.current_nb = CALCULATE_find_smallest_current(c_max, &i, stack_A);
		if (calc.current_nb == -1)
			break ;
		CALCULATE_ra_rb(&calc, stack_A, stack_B);
		calc.price = CALCULATE_price(calc.ra, calc.rb);
		if (calc.price < calc.cheapest)
		{
			calc.cheapest_number = calc.current_nb;
			calc.cheapest = calc.price;
		}
	}
	return (calc.cheapest_number);
}
