/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:49:43 by vlopatin          #+#    #+#             */
/*   Updated: 2025/01/28 16:16:39 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	copy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->new2d[i].x = map->original[i].x;
		map->new2d[i].y = map->original[i].y;
		map->new2d[i].z = map->original[i].z;
		map->new2d[i].color = map->original[i].color;
		i++;
	}
}


