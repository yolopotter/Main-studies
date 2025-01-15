/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:14 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 22:00:37 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorithm(int *stack_A, int *stack_B)
{
	int	stack_A_len;

	stack_A_len = stack_len(stack_A);
	if(is_sorted(stack_A))
		return (0);
	if (stack_A_len > 15)
		return (size_big_algorithm(stack_A_len, stack_A, stack_B));
	else if (stack_A_len > 3)
		return (size_small_algorithm(stack_A, stack_B));
	else if (stack_A_len > 0)
		return (size_mini_algorithm(stack_A_len, stack_A));
	return (-1);
}

void	fill_stack_B(int *stack_A, int *stack_B)
{
	int	i;

	i = 0;
	while (i < (stack_len(stack_A) + 1))
	stack_B[i++] = -1;
}

int main(int ac, char **av)
{
	int	*stack_A;
	int	*stack_B;

	if (ac < 2)
		return (0);
	stack_A = parsing(ac, av);
	if(!stack_A)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_B = malloc((stack_len(stack_A) + 1) * sizeof(int));
	if (!stack_B)
	{
		free(stack_A);
		write(2, "Memory allocation failed\n", 25);
		return (1);
	}
	fill_stack_B(stack_A, stack_B);
	algorithm(stack_A, stack_B);
	free(stack_A);
	free(stack_B);
	return (0);
}
