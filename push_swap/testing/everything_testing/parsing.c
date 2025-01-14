/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:48:56 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 13:48:58 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing(int ac, char **av)
{
	int	*nb_arr;
	int	len;
	// if (ac < 2)
	// 	return ERROR;
	if (ac == 2)
	{
		if (!validate_input_single(av[1]))
			return (NULL);
		nb_arr = parse_single(av[1]);
		len = arr_len(av[1]) + 1;
	}
	else if (ac > 2)
	{
		if (!validate_input_multiple(av))
			return (NULL);
		nb_arr = parse_multiple(ac, av);
		len = ac;
	}
	else
		nb_arr = NULL;
	if (!nb_arr)
		return (NULL);
	nb_arr = normalize_sequence(nb_arr, len);
	if (!nb_arr)
		return (NULL);
	return (nb_arr);
}

// int main(int ac, char **av) //parsing done, needs some testing little more
// {
// 	int *arr = parsing(ac, av);
// 	if(!arr)
// 	{
// 		printf("Error\n");
// 		return 0;
// 	}
// 	int i = 0;
// 	while (arr[i] != -1)
// 	{
// 		printf("%i \n", arr[i]);
// 		i++;
// 	}
// 	printf("%i \n", arr[i]);
// 	return 0;
// }
