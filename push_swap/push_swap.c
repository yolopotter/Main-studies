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

int	stack_len(int *stack)
{
	int len;

	len = 0;
	while(stack[len] != -1)
		len++;
	return (len);
}

int	push(int *dst, int *src)
{
	int	len_src;
	int	len_dst;
	int	temp;

	if (!src || !dst)
		return (0);
	len_src = stack_len(src);
	if (len_src == 0)
		return (0);
	len_dst = stack_len(dst);
	dst[len_dst + 1] = -1;
	dst[len_dst] = src[len_src - 1];
	src[len_src - 1] = -1;
	return (1);
}

int	rrotate(int *stack)
{
	int	i;
	int	len;
	int	temp;

	len = stack_len(stack);
	if (len == 0)
		return (1);
	if (!stack)
		return (1);
	temp = stack[0];
	i = 0;
	while(i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	return (0);
}

int	rotate(int *stack)
{
	int	len;
	int	temp;

	len = stack_len(stack);
	if (len == 0)
		return (1);
	if (!stack)
		return (1);
	temp = stack[len - 1];
	while(len > 0)
	{
		stack[len - 1] = stack[len - 2];
		len--;
	}
	stack[0] = temp;
	return (0);
}

int	find_closest_nb_to_end(int current, int *stack_A)
{
	return 3;
}

void	algorithm(int amount, int *stack_A, int *stack_B)
{
	int	chunck_size;
	int	current;
	int	closest_nb_position;

	current = 0;
	chunck_size = amount/10;
	while (current < amount)
		closest_nb_position = find_closest_nb_to_end(current, stack_A);

}

int count_amount(argv)
{

}

char	*ft_push_swap(char **argv)
{
	int	*stack_A;
	int	*stack_B;
	int	amount;

	if(!check_input(argv))
		return ("Error");
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
	print_result(stack_A);
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
