/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:24:37 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/14 16:09:25 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_array(int *arr) {
    if (arr == NULL) {
        return; // Handle null pointer
    }

    // Find the length of the array (excluding the -1 terminator)
    int length = 0;
    while (arr[length] != -1) {
        length++;
    }

    // Swap elements from the start and end moving towards the center
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

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
	reverse_array(nb_arr);
	return (nb_arr);
}
