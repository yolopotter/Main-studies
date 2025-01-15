/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ALGO_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:14 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:18 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_all_to_other(int *stack_A, int *stack_B)
{
	int len;
	int	min;

	len = 0;
	min = find_min(stack_B);
	len = stack_len(stack_B);
	while (stack_B[0] != min)
	{
		apply_rotation(stack_B);
		write(1, "rb\n", 3);
	}
	while (len > 0)
	{
		apply_push(stack_A, stack_B);
		write(1, "pa\n", 3);
		len--;
	}
}

int	algorithm(int amount, int *stack_A, int *stack_B)
{
	if(is_sorted(stack_A))
		return (0);
	if (amount > 15)
		return (size_big_algorithm(amount, stack_A, stack_B));
	else if (amount > 3)
		return (size_small_algorithm(stack_A, stack_B));
	else if (amount > 0)
		return (size_mini_algorithm(amount, stack_A));
	return (-1);
}

int main(int ac, char **av)
{
	int i;

	if (ac < 2)
		return (0);
	int *stack_A = parsing(ac, av);
	if(!stack_A)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	int *stack_B = malloc((stack_len(stack_A) + 1) * sizeof(int));
	if (!stack_B)
	{
		write(2, "Memory allocation failed\n", 25);
		return (1);
	}
	i = 0;
	while (i < (stack_len(stack_A) + 1))
		stack_B[i++] = -1;
	algorithm(stack_len(stack_A), stack_A, stack_B);
	free(stack_A);
	free(stack_B);
	return (0);
}
