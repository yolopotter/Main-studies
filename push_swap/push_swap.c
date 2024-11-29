/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:51:31 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/28 12:51:31 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_nb_to_end(int current, int *stack_A)
{
	return 3;
}

int	move_all_to_other(int *dst, int *src)
{
	int len;
	int ops;

	ops = 0;
	len = 0;
	len = stack_len(src);
	while (len > 0)
	{
		apply_push(dst, src);
		ops++;
		len--;
	}
	return (ops);
}

int	algorithm(int amount, int *stack_A, int *stack_B)
{
	// int	chunck_size;
	int	ops;
	int	current;
	// int	closest_nb_position;
	int i = 0;
	current = 0;
	ops = 0;
	// chunck_size = amount/10;
	// while (current < amount)
	// 	closest_nb_position = find_closest_nb_to_end(current, stack_A);
	while (current < amount)
	{
		i = 0;
		while (stack_A[i] != current)
			i++;
		if ((i >= stack_len(stack_A) / 2))
		{
			while ((stack_len(stack_A) - (i + 1)) > 0)
			{
				apply_rotation(stack_A);
				ops++;
				// printf("rr\n");
				i++;
			}
		}
		else
		{
			while (i >= 0)
			{
				apply_reverse_rotation(stack_A);
				ops++;
				// printf("rr\n");
				i--;
			}
		}
		apply_push(stack_B, stack_A);
		ops++;
		// printf("pa\n");
		current++;
	}
	ops += move_all_to_other(stack_A, stack_B);
	return (ops);
}

char	*ft_push_swap(char **argv)
{
	int	*stack_A;
	int	*stack_B;
	int	amount;

	if(!check_input(argv))
		return ("Error\n");
	amount = count_amount(argv);
	stack_A = (int *)malloc((amount + 1) * sizeof(int));
	if(!stack_A)
		return (NULL);
	stack_B = (int *)malloc((amount + 1) * sizeof(int));
	if(!stack_A)
		return (NULL);
	convert_to_int(argv, stack_A);
	simplify_numbers(stack_A);
	algorithm(amount, stack_A, stack_B);
	print_result();
	free(stack_A);
	stack_A = NULL;
	free(stack_B);
	stack_B = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error");
		return (1);
	}
	ft_push_swap(argv);
	return (0);
}
