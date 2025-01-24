/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:14 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 13:33:09 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorithm(int *stack_a, int *stack_b)
{
	int	stack_a_len;

	stack_a_len = stack_len(stack_a);
	if (is_sorted(stack_a))
		return (0);
	if (stack_a_len > 3)
		return (size_big_algorithm(stack_a_len, stack_a, stack_b));
	else if (stack_a_len > 0)
		return (size_mini_algorithm(stack_a_len, stack_a));
	return (-1);
}

void	fill_stack_b(int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	while (i < (stack_len(stack_a) + 1))
		stack_b[i++] = -1;
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parsing(ac, av);
	stack_b = malloc((stack_len(stack_a) + 1) * sizeof(int));
	if (!stack_b)
		exit_function(stack_a, 0);
	fill_stack_b(stack_a, stack_b);
	algorithm(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
