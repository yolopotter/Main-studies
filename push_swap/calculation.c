/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:56:27 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 12:13:52 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rotation_or_reverse(int pos, int *stack)
{
	int	rotations;

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

int	calc_find_smallest_current(int c_max, int *i, int *stack_a)
{
	while (stack_a[*i] != -1)
	{
		if (stack_a[*i] >= 0 && stack_a[*i] <= c_max)
		{
			return (stack_a[(*i)++]);
		}
		(*i)++;
	}
	return (-1);
}

int	calc_price(int ra, int rb)
{
	int	delta;
	int	price;

	delta = ra - rb;
	if ((ra > 0 && rb > 0) || (ra < 0 && rb < 0))
		price = ft_abs(delta) + ft_min(ft_abs(ra), ft_abs(rb));
	else
		price = ft_abs(delta);
	return (price);
}

void	calc_ra_rb(t_calc *calc, int *stack_a, int *stack_b)
{
	int	position;

	position = calc_find_current_position(calc->current_nb, stack_a);
	calc->ra = calc_rotation_or_reverse(position, stack_a);
	position = find_gap(calc->current_nb, stack_b);
	calc->rb = calc_rotation_or_reverse(position, stack_b);
}

int	calc_find_cheapest_nb(int c_max, int *stack_a, int *stack_b)
{
	int		i;
	t_calc	calc;

	i = 0;
	calc.cheapest = 1000000;
	while (stack_a[i] != -1)
	{
		calc.current_nb = calc_find_smallest_current(c_max, &i, stack_a);
		if (calc.current_nb == -1)
			break ;
		calc_ra_rb(&calc, stack_a, stack_b);
		calc.price = calc_price(calc.ra, calc.rb);
		if (calc.price < calc.cheapest)
		{
			calc.cheapest_number = calc.current_nb;
			calc.cheapest = calc.price;
		}
	}
	return (calc.cheapest_number);
}
