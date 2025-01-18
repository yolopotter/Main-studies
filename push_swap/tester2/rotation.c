/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:45:27 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/16 12:06:27 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_1(int *ra, int *rb, int *stack_a, int *stack_b)
{
	while ((*ra) < 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_a);
		apply_reverse_rotation(stack_b);
		(*rb)++;
		(*ra)++;
		ft_putstr_fd("rrr\n", 1);
	}
	while ((*ra) > 0 && (*rb) > 0)
	{
		apply_rotation(stack_a);
		apply_rotation(stack_b);
		(*rb)--;
		(*ra)--;
		ft_putstr_fd("rr\n", 1);
	}
}

static void	rotate_2(int *ra, int *rb, int *stack_a, int *stack_b)
{
	while ((*ra) > 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_b);
		apply_rotation(stack_a);
		(*rb)++;
		(*ra)--;
		ft_putstr_fd("rrb\n", 1);
		ft_putstr_fd("ra\n", 1);
	}
	while ((*ra) < 0 && (*rb) > 0)
	{
		apply_rotation(stack_b);
		apply_reverse_rotation(stack_a);
		(*rb)--;
		(*ra)++;
		ft_putstr_fd("rb\n", 1);
		ft_putstr_fd("rra\n", 1);
	}
}

static void	rotate_3(int *ra, int *rb, int *stack_a, int *stack_b)
{
	while ((*ra) == 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_b);
		(*rb)++;
		ft_putstr_fd("rrb\n", 1);
	}
	while ((*ra) < 0 && (*rb) == 0)
	{
		apply_reverse_rotation(stack_a);
		(*ra)++;
		ft_putstr_fd("rra\n", 1);
	}
}

static void	rotate_4(int *ra, int *rb, int *stack_a, int *stack_b)
{
	while ((*ra) == 0 && (*rb) > 0)
	{
		apply_rotation(stack_b);
		(*rb)--;
		ft_putstr_fd("rb\n", 1);
	}
	while ((*ra) > 0 && (*rb) == 0)
	{
		apply_rotation(stack_a);
		(*ra)--;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rotate(int ra, int rb, int *stack_a, int *stack_b)
{
	if ((ra < 0 && rb < 0) || (ra > 0 && rb > 0))
		rotate_1(&ra, &rb, stack_a, stack_b);
	if ((ra > 0 && rb < 0) || (ra < 0 && rb > 0))
		rotate_2(&ra, &rb, stack_a, stack_b);
	if ((ra == 0 && rb < 0) || (ra < 0 && rb == 0))
		rotate_3(&ra, &rb, stack_a, stack_b);
	if ((ra == 0 && rb > 0) || (ra > 0 && rb == 0))
		rotate_4(&ra, &rb, stack_a, stack_b);
}
