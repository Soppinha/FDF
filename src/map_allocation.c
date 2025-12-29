/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:10:37 by svaladar          #+#    #+#             */
/*   Updated: 2025/12/29 17:06:44 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	allocate_z_scale(t_map *map)
{
	int	i;

	map->z_scale = (int **)malloc(sizeof(int *) * map->height);
	if (!map->z_scale)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->z_scale[i] = (int *)malloc(sizeof(int) * map->width);
		if (!map->z_scale[i])
		{
			while (--i >= 0)
				free(map->z_scale[i]);
			free(map->z_scale);
		}
		i++;
	}
	return (1);
}

int	allocate_colors(t_map *map)
{
	int	i;

	map->color = (int **)malloc(sizeof(int *) * map->height);
	if (!map->color)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->color[i] = (int *)malloc(sizeof(int *) * map->width);
		if (!map->color[i])
		{
			while (--i >= 0)
				free(map->color);
			free(map->color);
		}
		i++;
	}
	return (1);
}

int	allocate_map(t_map *map)
{
	int i;

	if (!allocate_z_scale(map))
		return (0);
	if (!allocate_colors(map))
	{
		i = 0;
		while (i < map->height)
			free(map->z_scale);
		free(map->z_scale);
		return (0);
	}
	return (1);
}
