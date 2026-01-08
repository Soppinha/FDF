/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:43:37 by svaladar          #+#    #+#             */
/*   Updated: 2026/01/08 19:39:44 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0;
}

t_point	**init_coordinates(int width, int depth)
{
	t_point	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(width * sizeof(t_point *));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordinates[i] = alloc_row(depth);
		if (!coordinates[i])
			free_allocated_coords(coordinates, i);
		j = 0;
		while (j < depth)
		{
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			coordinates[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
}

void	*free_allocated_coords(t_point **coordinates, int count)
{
	while (--count >= 0)
		free(coordinates[count]);
	free(coordinates);
	return (NULL);
}

t_point	*alloc_row(int depth)
{
	t_point	*row;
	int		j;

	row = malloc(depth * sizeof(t_point));
	if (!row)
		return (NULL);
	j = 0;
	while (j < depth)
	{
		init_point(&row[j]);
		j++;
	}
	return (row);
}
