/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:35:14 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/17 10:59:10 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_prefix(char c)
{
	if (c == '-' || c == '+')
		return (1);
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

int	check_overflow(int sign, long int res, int *error)
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

int	ft_atoi_error(char *str, int *i, int *error)
{
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-')
	{
		(*i)++;
		sign *= -1;
	}
	if (str[*i] == '+')
		(*i)++;
	while (str[*i] && !ft_isspace(str[*i]))
	{
		res = res * 10 + str[*i] - '0';
		if (!check_overflow(sign, res, error))
			return (0);
		(*i)++;
	}
	return (res * sign);
}
