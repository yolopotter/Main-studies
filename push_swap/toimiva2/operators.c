/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:49:02 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 14:49:12 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_swap(int *src)
{
	int temp;
	int len;

	len = stack_len(src);
	if (!src || len == 0)
		return (0);
	if (len == 1)
		return (1);
	temp = src[len - 1];
	src[len - 1] = src[len - 2];
	src[len - 2] = temp;
	return (1);
}
int	apply_push(int *dst, int *src)
{
	int	len_src;
	int	len_dst;

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

int	apply_reverse_rotation(int *stack)
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

int	apply_rotation(int *stack)
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
