/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:35:10 by mwallage          #+#    #+#             */
/*   Updated: 2025/01/23 14:28:30 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	valid_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	filename += len - 4;
	return (ft_strncmp(filename, ".fdf", 4) == 0);
}

void	make_upper(unsigned int i, char *c)
{
	i++;
	*c = ft_toupper(*c);
}

void	draw_reset(mlx_image_t *image)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			mlx_put_pixel(image, j, i, BACKGROUND);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void display_2d_map(t_map *map)
{
    int i, j;
    t_point2d *point;

    printf("NEW:\n");
    printf("Rows: %d, Columns: %d\n", map->rows, map->cols);
    printf("Height Range: Low = %.2d, High = %.2d\n", map->low, map->high);
    printf("=========================================\n");

    for (i = 0; i < map->rows; i++)
    {
        for (j = 0; j < map->cols; j++)
        {
            point = &(map->grid2d[i][j]);
            printf("Point[%d][%d]: x=%.2d, y=%.2d, z=%.2d, color=0x%x\n",
                   i, j, point->x, point->y, point->z, point->rgba);
        }
        printf("\n");
    }
	printf("angles 1: %f, 2: %f, 3: %f\n", map->xrotate, map->yrotate, map->zrotate);
    printf("=========================================\n");
}

void display_3d_map(t_map *map)
{
    int i, j;
    t_point3d *point;

    printf("ORIGINAL:\n");
    printf("Rows: %d, Columns: %d\n", map->rows, map->cols);
    printf("Height Range: Low = %.2d, High = %.2d\n", map->low, map->high);
    printf("=========================================\n");

    for (i = 0; i < map->rows; i++)
    {
        for (j = 0; j < map->cols; j++)
        {
            point = &(map->grid3d[i][j]);
            printf("Point[%d][%d]: x=%.2f, y=%.2f, z=%.2f\n",
                   i, j, point->x, point->y, point->z);
        }
        printf("\n");
    }
	printf("angles 1: %f, 2: %f, 3: %f\n", map->xrotate, map->yrotate, map->zrotate);
    printf("=========================================\n");
}
