/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:54:16 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 11:12:58 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input_multiple(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				return (0);
			j++;
		}
		if (!validate_input_single(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*extract_multiple(int ac, char **av)
{
	int	i;
	int	*nb_arr;
	int	error;
	int	index;

	error = 0;
	nb_arr = malloc(ac * sizeof(int));
	if (!nb_arr)
		exit_function(nb_arr, 0);
	i = 1;
	while (av[i])
	{
		index = 0;
		nb_arr[i - 1] = ft_atoi_error(av[i], &index, &error);
		if (error)
			exit_function(nb_arr, 1);
		i++;
	}
	if (!check_repeat(nb_arr, i - 1))
		exit_function(nb_arr, 1);
	return (nb_arr);
}
