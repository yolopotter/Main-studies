/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:09:46 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/18 11:54:50 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_function(int *arr, int error)
{
	if (error == 0)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		free(arr);
		exit (1);
	}
	else if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free(arr);
		exit (1);
	}
}
