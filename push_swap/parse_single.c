/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:36:48 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/09 13:07:46 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// len returns amount of numbers 1 2 3 4 is len = 4
int	arr_len(char *arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		while (arr[i] == ' ')
			i++;
		while (is_num(arr[i]))
			i++;
		count++;
		while (arr[i] == ' ')
			i++;
	}
	return (count);
}

int *parse_single(char *arr)
{
	int	i;
	int	j;
	int	nb;
	int	*nb_arr;
	int error;

	i = 0;
	j = 0;
	error = 0;
	nb_arr = malloc((arr_len(arr) + 1) * sizeof(int));
	if (!nb_arr)
		return (NULL);
	while (arr[i])
	{
		nb = ft_atoi(arr, &i, &error);
		if (error)
			return (NULL);
		nb_arr[j] = nb;
		j++;
	}
	if (!check_repeat(nb_arr, arr_len(arr)))
		return (NULL);
	return (nb_arr);
}

int	validate_input_single(char *str)
{
	int	i;
	i = 0;
	while(str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && !is_space(str[i]))
			return (0);
		while (is_space(str[i]))
			i++;
	}
	return (1);
}
