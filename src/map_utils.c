/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:32:13 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 19:39:23 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->coordinates[x][y].x -= map->max_x / 2;
			map->coordinates[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}

float	scale_to_fit(t_map *map, int win_width, int win_height)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	if (map->max_x == 0 || map->max_y == 0)
		return (1.0);
	scale_x = win_width / map->max_x;
	scale_y = win_height / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (1);
	return (scale_factor * 0.2);
}

void	reset(t_fdf *fdf)
{
	fdf->cam->scale_factor = scale_to_fit(fdf->map, fdf->win_x, fdf->win_y);
	fdf->cam->scale_z = 1;
	fdf->cam->move_x = fdf->win_x / 2;
	fdf->cam->move_y = fdf->win_y / 2;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}
