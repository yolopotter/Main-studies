/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:36:48 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/17 19:24:35 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_len(char *arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		while (ft_isspace(arr[i]))
			i++;
		while (is_prefix(arr[i]))
			i++;
		while (ft_isdigit(arr[i]))
			i++;
		count++;
		while (ft_isspace(arr[i]))
			i++;
	}
	return (count);
}

int	*extract_single(char *arr)
{
	int	i;
	int	j;
	int	nb;
	int	*nb_arr;
	int	error;

	i = 0;
	j = 0;
	error = 0;
	nb_arr = malloc((arr_len(arr) + 1) * sizeof(int));
	if (!nb_arr)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		exit (1);
	}
	while (arr[i])
	{
		nb = ft_atoi_error(arr, &i, &error);
		if (error)
		{
			free(nb_arr);
			return (NULL);
		}
		nb_arr[j++] = nb;
	}
	if (!check_repeat(nb_arr, arr_len(arr)))
	{
		free(nb_arr);
		return (NULL);
	}
	return (nb_arr);
}

int	validate_input_single(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && !ft_isspace(str[i]))
			return (0);
		while (ft_isspace(str[i]))
			i++;
	}
	return (1);
}
