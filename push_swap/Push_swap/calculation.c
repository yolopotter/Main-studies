/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:56:27 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/17 11:38:29 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_rotation_or_reverse(int pos, int *stack)
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

int	cal_find_smallest_current(int c_max, int *i, int *stack_a)
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

int	cal_price(int ra, int rb)
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

static void	cal_ra_rb(t_calc *cal, int *src_stack, int *dst_stack, t_dir dir)
{
	int	position;

	position = cal_find_current_position(cal->curr_nb, src_stack);
	if (dir == A_TO_B)
	{
		cal->ra = cal_rotation_or_reverse(position, src_stack);
		position = find_gap(cal->curr_nb, dst_stack, A_TO_B);
		cal->rb = cal_rotation_or_reverse(position, dst_stack);
	}
	else
	{
		cal->rb = cal_rotation_or_reverse(position, src_stack);
		position = find_gap(cal->curr_nb, dst_stack, B_TO_A);
		cal->ra = cal_rotation_or_reverse(position, dst_stack);
	}
}

int	cal_find_cheapest_nb(int c_max, int *src_stack, int *dst_stack, t_dir dir)
{
	int		i;
	t_calc	cal;

	i = 0;
	cal.cheapest = 1000000;
	while (src_stack[i] != -1)
	{
		cal.curr_nb = cal_find_smallest_current(c_max, &i, src_stack);
		if (cal.curr_nb == -1)
			break ;
		cal_ra_rb(&cal, src_stack, dst_stack, dir);
		cal.price = cal_price(cal.ra, cal.rb);
		if (cal.price < cal.cheapest)
		{
			cal.cheapest_number = cal.curr_nb;
			cal.cheapest = cal.price;
		}
	}
	return (cal.cheapest_number);
}
