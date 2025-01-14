/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:45:27 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 15:16:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_1(int *ra, int *rb, int *stack_A, int *stack_B)
{
	int	ops;

	ops = 0;
	while ((*ra) < 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_A);
		apply_reverse_rotation(stack_B);
		(*rb)++;
		(*ra)++;
		write(1, "rrr\n", 4);
		ops += 1;
	}
	while ((*ra) > 0 && (*rb) > 0)
	{
		apply_rotation(stack_A);
		apply_rotation(stack_B);
		(*rb)--;
		(*ra)--;
		write(1, "rr\n", 3);
		ops += 1;
	}
	return (ops);
}
static int	rotate_2(int *ra, int *rb, int *stack_A, int *stack_B)
{
	int ops;

	ops = 0;
	while ((*ra) > 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_B);
		apply_rotation(stack_A);
		(*rb)++;
		(*ra)--;
		write(1, "rrb\n", 4);
		write(1, "ra\n", 3);
		ops += 2;
	}
	while ((*ra) < 0 && (*rb) > 0)
	{
		apply_rotation(stack_B);
		apply_reverse_rotation(stack_A);
		(*rb)--;
		(*ra)++;
		write(1, "rb\n", 4);
		write(1, "rra\n", 4);
		ops += 2;
	}
	return ops;
}

static int	rotate_3(int *ra, int *rb, int *stack_A, int *stack_B)
{
	int ops;

	ops = 0;
	while ((*ra) == 0 && (*rb) < 0)
	{
		apply_reverse_rotation(stack_B);
		(*rb)++;
		write(1, "rrb\n", 4);
		ops += 1;
	}
	while ((*ra) < 0 && (*rb) == 0)
	{
		apply_reverse_rotation(stack_A);
		(*ra)++;
		write(1, "rra\n", 4);
		ops += 1;
	}
	return (ops);
}

static int	rotate_4(int *ra, int *rb, int *stack_A, int *stack_B)
{
	int ops;

	ops = 0;
	while ((*ra) == 0 && (*rb) > 0)
	{
		apply_rotation(stack_B);
		(*rb)--;
		write(1, "rb\n", 3);
		ops += 1;
	}
	while ((*ra) > 0 && (*rb) == 0)
	{
		apply_rotation(stack_A);
		(*ra)--;
		write(1, "ra\n", 3);
		ops += 1;
	}
	return (ops);
}
int	rotate(int ra, int rb, int *stack_A, int *stack_B)
{
	int	ops;

	ops = 0;
	if ((ra < 0 && rb < 0) || (ra > 0 && rb > 0))
		ops += rotate_1(&ra, &rb, stack_A, stack_B);
	if ((ra > 0 && rb < 0) || (ra < 0 && rb > 0))
		ops += rotate_2(&ra, &rb, stack_A, stack_B);
	if ((ra == 0 && rb < 0) || (ra < 0 && rb == 0))
		ops += rotate_3(&ra, &rb, stack_A, stack_B);
	if ((ra == 0 && rb > 0) || (ra > 0 && rb == 0))
		ops += rotate_4(&ra, &rb, stack_A, stack_B);
	return (ops);
}
