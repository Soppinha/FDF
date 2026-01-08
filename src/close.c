/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:08:35 by cado-car          #+#    #+#             */
/*   Updated: 2026/01/07 22:40:13 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	close_coordinates(t_point **coordinates, int width);

void	close_all(t_fdf *fdf, int exit_code)
{
	if (!fdf)
		exit(exit_code);
	if (fdf->map && fdf->map->coordinates)
		close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	if (fdf->map)
		free(fdf->map);
	if (fdf->image && fdf->mlx && fdf->image->image)
		mlx_destroy_image(fdf->mlx, fdf->image->image);
	if (fdf->image)
		free(fdf->image);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
	error(exit_code);
	exit(exit_code);
}

void	close_map(t_fdf *fdf, int exit_code)
{
	if (!fdf)
		exit(exit_code);
	if (fdf->map && fdf->map->coordinates)
		close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	if (fdf->map)
		free(fdf->map);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
	error(exit_code);
	exit(exit_code);
}

int	close_handle(t_fdf *fdf)
{
	close_all(fdf, 0);
	return (0);
}

static void	close_coordinates(t_point **coordinates, int width)
{
	int		i;

	if (!coordinates)
		return ;
	i = 0;
	while (i < width)
	{
		if (coordinates[i])
			free(coordinates[i]);
		i++;
	}
	free(coordinates);
}
