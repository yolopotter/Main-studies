/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:35:14 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 13:49:03 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	check_repeat(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] == arr[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_overflow(int sign, long int res, int *error)
{
	if (res > INT_MAX && sign == 1)
	{
		*error = 1;
		return (0);
	}
	else if (res > (long int)INT_MAX + 1 && sign == -1)
	{
		*error = 1;
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str, int *i, int *error)
{
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	while (is_space(str[*i]))
		(*i)++;
	if (str[*i] == '-')
	{
		(*i)++;
		sign *= -1;
	}
	while(str[*i] && str[*i] != ' ')
	{
		res = res * 10 + str[*i] - '0';
		if (!check_overflow(sign, res, error))
			return (0);
		(*i)++;
	}
	return (res * sign);
}

int	is_num(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}
