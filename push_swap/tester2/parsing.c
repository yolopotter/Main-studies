/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:37 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 11:43:40 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_array(int *arr)
{
	int	i;
	int	len;
	int	temp;

	if (arr == NULL)
		return ;
	len = stack_len(arr);
	i = 0;
	while (i < len / 2)
	{
		temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
		i++;
	}
}

static int	*parsing_single(char *av, int *len)
{
	int	*nb_arr;

	if (!av[0])
		exit_function(NULL, 1);
	if (!validate_input_single(av))
		exit_function(NULL, 1);
	nb_arr = extract_single(av);
	*len = arr_len(av) + 1;
	return (nb_arr);
}

static int	*parsing_multiple(int ac, char **av, int *len)
{
	int	*nb_arr;

	if (!validate_input_multiple(av))
		exit_function(NULL, 1);
	nb_arr = extract_multiple(ac, av);
	*len = ac;
	return (nb_arr);
}

int	*parsing(int ac, char **av)
{
	int	*nb_arr;
	int	len;

	if (ac == 2)
		nb_arr = parsing_single(av[1], &len);
	else if (ac > 2)
		nb_arr = parsing_multiple(ac, av, &len);
	nb_arr = normalize_sequence(nb_arr, len);
	reverse_array(nb_arr);
	return (nb_arr);
}
