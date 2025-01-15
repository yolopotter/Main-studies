/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:45:27 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 15:14:50 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_1(int *ra, int *rb, int *stack_A, int *stack_B)
{
	while ((*ra) < 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_A);
		apply_reverse_rotation(stack_B);
		(*rb)++;
		(*ra)++;
		write(1, "rrr\n", 4);
	}
	while ((*ra) > 0 && (*rb) > 0)
	{
		apply_rotation(stack_A);
		apply_rotation(stack_B);
		(*rb)--;
		(*ra)--;
		write(1, "rr\n", 3);
	}
}

static void	rotate_2(int *ra, int *rb, int *stack_A, int *stack_B)
{
	while ((*ra) > 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_B);
		apply_rotation(stack_A);
		(*rb)++;
		(*ra)--;
		write(1, "rrb\n", 4);
		write(1, "ra\n", 3);
	}
	while ((*ra) < 0 && (*rb) > 0)
	{
		apply_rotation(stack_B);
		apply_reverse_rotation(stack_A);
		(*rb)--;
		(*ra)++;
		write(1, "rb\n", 3);
		write(1, "rra\n", 4);
	}
}

static void	rotate_3(int *ra, int *rb, int *stack_A, int *stack_B)
{
	while ((*ra) == 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_B);
		(*rb)++;
		write(1, "rrb\n", 4);
	}
	while ((*ra) < 0 && (*rb) == 0)
	{
		apply_reverse_rotation(stack_A);
		(*ra)++;
		write(1, "rra\n", 4);
	}
}

static void	rotate_4(int *ra, int *rb, int *stack_A, int *stack_B)
{
	while ((*ra) == 0 && (*rb) > 0)
	{
		apply_rotation(stack_B);
		(*rb)--;
		write(1, "rb\n", 3);
	}
	while ((*ra) > 0 && (*rb) == 0)
	{
		apply_rotation(stack_A);
		(*ra)--;
		write(1, "ra\n", 3);
	}
}

void	rotate(int ra, int rb, int *stack_A, int *stack_B)
{
	if ((ra < 0 && rb < 0) || (ra > 0 && rb > 0))
		rotate_1(&ra, &rb, stack_A, stack_B);
	if ((ra > 0 && rb < 0) || (ra < 0 && rb > 0))
		rotate_2(&ra, &rb, stack_A, stack_B);
	if ((ra == 0 && rb < 0) || (ra < 0 && rb == 0))
		rotate_3(&ra, &rb, stack_A, stack_B);
	if ((ra == 0 && rb > 0) || (ra > 0 && rb == 0))
		rotate_4(&ra, &rb, stack_A, stack_B);
}
