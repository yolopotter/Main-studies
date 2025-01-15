/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:54:16 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/15 21:53:44 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input_multiple(char **av)
{
	int	i;
	i = 1;
	while (av[i])
	{
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
		return (NULL);
	i = 1;
	while (av[i])
	{
		index = 0;
		nb_arr[i - 1] = ft_atoi(av[i], &index, &error);
		if (error)
			return (NULL);
		i++;
	}
	if (!check_repeat(nb_arr, i - 1))
		return (NULL);
	return (nb_arr);
}
